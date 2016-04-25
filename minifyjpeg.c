#include "minifyjpeg.h"
#include "magickminify.h"

/* Implement the needed server-side functions here */

img* minify_img_1_svc(img input_img, struct svc_req *rqstp)
{
	static img output_img;
	magickminify_init();
	output_img.img_val = (char*)magickminify(input_img.img_val, input_img.img_len, &output_img.img_len);
	magickminify_cleanup();
	return &output_img;
}