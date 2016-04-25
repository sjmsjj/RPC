#include <stdlib.h>
#include <stdio.h>
#include <rpc/pmap_clnt.h>
#include <memory.h>
#include "minifyjpeg.h"
#include "minifyjpeg_xdr.c"
#include "minifyjpeg_clnt.c"

CLIENT* get_minify_client(char *server){
    CLIENT *cl;

    /* Your code here */
    cl = clnt_create(server, img_prog, img_version, "tcp");
    if(cl == NULL)
    {
    	clnt_pcreateerror(server);
    	exit(1);
    }
    return cl;
}

void* minify_via_rpc(CLIENT *cl, void* src_val, size_t src_len, size_t *dst_len){

	/*Your code here */
	img input_img;
	img* output_img;
	input_img.img_len = (u_int)src_len;
	input_img.img_val = (char*)src_val;

	output_img = minify_img_1(input_img, cl);
	*dst_len = output_img->img_len;
	return output_img->img_val;
}