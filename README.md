# Steganography

## Find the difference between these two images

![](image_with_a_secret_message.png) ![](normal_image.png)

As enticing as it may be to give up, don't be discouraged. When filmmaker and literary visionary Michael Scott faced a similar problem, he never accepted defeat. Then again, he also never made any progress. Despite Michael's failures, you *can* succeed in this seemingly impossible task using the power of STEGANOGRAPHY.

> "Steganography is the practice of concealing a message within another message or a physical object." (Wikipedia definition)

## Least Significant Bit

Least significant bit is an image steganography technique that conceals messages inside images. Despite the complicated sounding name, you can understand the concept in the next 60 seconds. Ready?

Consider the number 1,000,000. If you change that to 1,300,000, that seems like a noticeable change, but 1,000,003 is practically the same. By changing the least significant digit, we can encode information in a number without drastically changing its value. The red, green, and blue image channels give numerical values for RGB, and they don't change much when you add or subtract 1 from them. By changing 255 to 254 or 120 to 121, we can encode information in the RGB values of pixels by checking whether it's even or odd. Putting those together, we get a series of 1's and 0's that we can turn into readable text.

Great, now you know what's going on, but how do you actually encode and decode messages practically? All you need to do is add a main function to `lsb.c` and add the following lines:

### Reading Messages

```C
ppm_t *ppm = read_ppm("image_with_a_secret_message.ppm");
read_message(ppm);
ppm_free(ppm);
return 0;
```

### Hiding Messages

```C
ppm_t *ppm = read_ppm("normal_image.ppm");
hide_message(ppm, "Your secret message goes here.");
write_ppm(ppm);
ppm_free(ppm);
return 0;
```

Note that you will have to pipe this output into a file: `./a.out > your_file_name.ppm` after compiling.

Happy sleuthing!