import os

def count_images(dataset_path):
    image_counts = {}
    image_extensions = ('.jpg', '.jpeg', '.png', '.gif', '.bmp', '.tiff')

    if not os.path.isdir(dataset_path):
        print(f"Error: Dataset path '{dataset_path}' is not a valid directory.")
        return image_counts

    for class_folder in os.listdir(dataset_path):
        class_path = os.path.join(dataset_path, class_folder)
        if os.path.isdir(class_path):
            count = 0
            for root, _, files in os.walk(class_path):
                for file in files:
                    if file.lower().endswith(image_extensions):
                        count += 1
            image_counts[class_folder] = count
    return image_counts
dataset_path = '/Users/shreejalbhattarai/Downloads/OP_Rolling_Ball_Imgs-2'
counts = count_images(dataset_path)

if counts:
    print(f"Image counts in '{dataset_path}':")
    for class_name, count in counts.items():
        print(f"  Class '{class_name}': {count} images")
else:
    print("No image counts found. Please check the dataset path and structure, or ensure there are images with common extensions.")