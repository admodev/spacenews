// System libs
#include <iostream>

// Project libs
#include "../include/httplibapi.h"

int main(int argc, char *argv)
{
	make_request("https://exoplanetarchive.ipac.caltech.edu/cgi-bin/nstedAPI/nph-nstedAPI?table=cumulative&where=koi_prad%3C2%20and%20koi_teq%3E180%20and%20koi_teq%3C303%20and%20koi_disposition%20like%20%27CANDIDATE%27");

	return 0;
}

