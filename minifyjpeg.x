
typedef opaque img<>;

program img_prog
{
	version img_version
	{
	    img minify_img(img) = 1;
	} = 1;
} = 0x20000002;