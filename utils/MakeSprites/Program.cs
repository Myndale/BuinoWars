using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace MakeSprites
{
	class Program
	{
		static void Main(string[] args)
		{
			var bmp = new Bitmap(@"..\..\..\..\assets\sprites.png");
			PixelFormat pxf = PixelFormat.Format24bppRgb;

			// Lock the bitmap's bits.
			Rectangle rect = new Rectangle(0, 0, bmp.Width, bmp.Height);
			BitmapData bmpData =
			bmp.LockBits(rect, ImageLockMode.ReadWrite, pxf);

			// Get the address of the first line.
			IntPtr ptr = bmpData.Scan0;

			// Declare an array to hold the bytes of the bitmap. 
			// int numBytes = bmp.Width * bmp.Height * 3; 
			int numBytes = bmpData.Stride * bmp.Height;
			byte[] rgbValues = new byte[numBytes];

			// Copy the RGB values into the array.
			Marshal.Copy(ptr, rgbValues, 0, numBytes);

			// Manipulate the bitmap, such as changing the 
			// blue value for every other pixel in the the bitmap. 
			//for (int counter = 0; counter < rgbValues.Length; counter += 6)
				//rgbValues[counter] = 255;

			// Copy the RGB values back to the bitmap
			//Marshal.Copy(rgbValues, 0, ptr, numBytes);

			// Unlock the bits.
			bmp.UnlockBits(bmpData);

			for (int ty=0; ty<4; ty++)
				for (int tx = 0; tx < 8; tx++)
				{
					Console.Write("\t{6, 6, ");
					for (int dy = 0; dy < 6; dy++)
					{
						if (dy != 0)
							Console.Write(", ");

						int pixel = 0;
						for (int dx = 0; dx < 6; dx++)
						{
							int sx = tx * 6 + dx;
							int sy = ty * 6 + dy;
							int offset = sy * bmp.Width + sx;
							if (rgbValues[offset*3]==0)
								pixel |= (0x80 >> dx);
						}
						Console.Write("0x{0:x2}", pixel);
					}
					Console.WriteLine("},");
				}

			Console.ReadKey();
		}

		
	}
}
