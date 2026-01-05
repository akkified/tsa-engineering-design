from flask import Flask, Response, request, render_template_string
from ultralytics import YOLO
import serial
import time
import cv2
import numpy as np

app = Flask(__name__)

try:
    model = YOLO("lab_items_v1.pt")
except Exception as e:
    model = None

try:
    arduino = serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=1)
except Exception as e:
    arduino = None

cap = cv2.VideoCapture(0)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

def send_to_arduino(gantry, j1, j2, j3, j4):
    command = f"{gantry},{j1},{j2},{j3},{j4}\n"
    if arduino:
        arduino.write(command.encode())

def generate_frames():
    while True:
        success, frame = cap.read()
        if not success:
            break
        
        if model:
            results = model(frame, conf=0.5, stream=True)
            for r in results:
                frame = r.plot()
            
        ret, buffer = cv2.imencode('.jpg', frame)
        yield (b'--frame\r\n'
               b'Content-Type: image/jpeg\r\n\r\n' + buffer.tobytes() + b'\r\n')

def calculate_movement(pixel_x, pixel_y):
    gantry_steps = int((pixel_x / 640) * 1000)
    j1, j2, j3, j4 = 500, 750, 100, 0
    send_to_arduino(gantry_steps, j1, j2, j3, j4)

@app.route('/')
def index():
    return render_template_string("""
        <!DOCTYPE html>
        <html>
        <head><title>Lab Robot Brain</title><script src="https://cdn.tailwindcss.com"></script></head>
        <body class="bg-gray-100 p-10 flex flex-col items-center">
            <h1 class="text-3xl font-bold mb-5">🧪 Lab Assistant Live Feed</h1>
            <div class="relative inline-block border-8 border-white shadow-2xl rounded-lg overflow-hidden">
                <img id="feed" src="{{ url_for('video_feed') }}" class="cursor-crosshair">
            </div>
            <script>
                document.getElementById('feed').onclick = function(e) {
                    const rect = this.getBoundingClientRect();
                    const x = Math.round((e.clientX - rect.left) * (640 / rect.width));
                    const y = Math.round((e.clientY - rect.top) * (480 / rect.height));
                    fetch('/click', {
                        method: 'POST',
                        headers: {'Content-Type': 'application/json'},
                        body: JSON.stringify({x: x, y: y})
                    });
                };
            </script>
        </body>
        </html>
    """)

@app.route('/video_feed')
def video_feed():
    return Response(generate_frames(), mimetype='multipart/x-mixed-replace; boundary=frame')

@app.route('/click', methods=['POST'])
def handle_click():
    data = request.json
    calculate_movement(data['x'], data['y'])
    return {"status": "success"}

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=5000, threaded=True)