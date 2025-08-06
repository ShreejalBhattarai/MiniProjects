from PIL import Image

def process_image_quarters(image_path):
    try:
        original_image = Image.open(image_path)
        width, height = original_image.size

        # Calculate dimensions for each quarter
        half_width = width // 2
        half_height = height // 2

        # Define the bounding boxes for cropping
        # (left, upper, right, lower)
        top_left_box = (0, 0, half_width, half_height)
        top_right_box = (half_width, 0, width, half_height)
        bottom_left_box = (0, half_height, half_width, height)
        bottom_right_box = (half_width, half_height, width, height)

        boxes = {
            "top_left": top_left_box,
            "top_right": top_right_box,
            "bottom_left": bottom_left_box,
            "bottom_right": bottom_right_box,
        }

        # Create a new image with the original dimensions, to paste onto
        new_quarter_size = (width, height)

        for name, box in boxes.items():
            # Crop the quarter
            cropped_quarter = original_image.crop(box)

            # Create a new blank image with the original dimensions
            # You might want to specify a background color, e.g., (255, 255, 255) for white
            new_image_for_quarter = Image.new('RGB', new_quarter_size, (0, 0, 0)) # Black background

            # Resize the cropped quarter to fill the new image
            # The .resize() method takes a tuple (new_width, new_height)
            # Since we want it to fill the original size, we resize it to (width, height)
            resized_quarter = cropped_quarter.resize(new_quarter_size, Image.Resampling.LANCZOS)

            # Paste the resized quarter onto the new image.
            # Since resized_quarter is already the target size, just paste at (0,0)
            new_image_for_quarter.paste(resized_quarter, (0, 0))

            # Save the new image
            output_filename = f"output_{name}_{image_path.split('/')[-1]}" # Adds original filename at end
            new_image_for_quarter.save(output_filename)
            print(f"Saved: {output_filename}")

    except FileNotFoundError:
        print(f"Error: Image not found at {image_path}")
    except Exception as e:
        print(f"An error occurred: {e}")

# Example usage:
# Replace 'your_image.jpg' with the actual path to your image file
# process_image_quarters('your_image.jpg')
process_image_quarters('/Users/shreejalbhattarai/Downloads/lord_krishna.jpeg')