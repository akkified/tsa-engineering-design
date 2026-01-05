from ultralytics import YOLO
model = YOLO("yolov8s.pt")

results = model.train(data="/Users/akki/lab-items/data.yaml", epochs=50, imgsz=800, patience=20, hsv_s=0.2, degrees=2)
metrics = model.val()

print("Model's performance metrics:", metrics)