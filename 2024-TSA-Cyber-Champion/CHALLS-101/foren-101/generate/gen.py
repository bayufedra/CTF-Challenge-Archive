from PIL import Image, ImageDraw, ImageFont

def character_to_image(character, font_size=500, image_size=(50, 50), background_color=(255, 255, 255), text_color=(0, 0, 0)):
    image = Image.new("RGB", image_size, background_color)
    font = ImageFont.load_default()
    draw = ImageDraw.Draw(image)
    text_bbox = draw.textbbox((0, 0), character, font=font)
    x = (image_size[0] - text_bbox[2]) // 2
    y = (image_size[1] - text_bbox[3]) // 2
    draw.text((x, y), character, font=font, fill=text_color)
    return image


flag = "TSA{Forensic_101_0d1b25a70976d70f}"
for c in range(len(flag)):
    image = character_to_image(flag[c])
    image.save(f"{c+1}.png")
