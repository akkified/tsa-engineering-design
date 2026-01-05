import csv

def generate_markdown_table(csv_file):
    markdown_table = "| Item | Description | Quantity | Link |\n"
    markdown_table += "| :--- | :--- | :--- | :--- |\n"
    
    with open(csv_file, mode='r', encoding='utf-8') as f:
        reader = csv.DictReader(f)
        for row in reader:
            # Assumes your CSV has headers: Item, Description, Quantity, Link
            markdown_table += f"| {row['Item']} | {row['Description']} | {row['Quantity']} | [Link]({row['Link']}) |\n"
    
    return markdown_table

def update_readme(readme_path, table_content):
    with open(readme_path, 'r', encoding='utf-8') as f:
        content = f.read()

    # Look for the BOM markers to know where to inject the table
    start_marker = "Bill of Materials"
    end_marker = "*update_bom.py is a script"
    
    if start_marker in content:
        upper_part = content.split(start_marker)[0]
        try:
            lower_part = content.split(end_marker)[1]
            new_content = f"{upper_part}{start_marker}\n\n{table_content}\n\n*(For a full list{lower_part}"
            
            with open(readme_path, 'w', encoding='utf-8') as f:
                f.write(new_content)
            print("README.md updated successfully!")
        except IndexError:
            print("Could not find the end of the BOM section. Check your README formatting.")
    else:
        print("Could not find BOM section in README.")

if __name__ == "__main__":
    table = generate_markdown_table('BOM.csv')
    update_readme('README.md', table)