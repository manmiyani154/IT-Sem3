import os

name = input("Enter your name: ")
enroll = input("Enter your enrollment number: ")

output_folder = enroll

if not os.path.exists(output_folder):
    os.makedirs(output_folder)

for i in range(1, 20):
    file_name = f"Prog{i}.c"
    
    if not os.path.exists(file_name):
        print(f"{file_name} not found. Skipping.")
        continue

    with open(file_name, 'r') as f:
        lines = f.readlines()

    new_lines = []
    inserted = False

    for line in lines:
        new_lines.append(line)
        if 'main' in line and '{' in line and not inserted:
            new_lines.append(f'    printf("Name: {name}\\n");\n')
            new_lines.append(f'    printf("Enrollment No: {enroll}\\n\\n");\n')
            inserted = True

    output_path = os.path.join(output_folder, file_name)
    with open(output_path, 'w') as f:
        f.writelines(new_lines)

    print(f"✅ Modified and saved: {output_path}")
