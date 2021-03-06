#include <stdio.h>
#include <vector>

#include "plumbingpieces.h"

#include "fileformats/adamfilewriter.h"

/**
 * Uses the ".adam" extension
 */
string adamfilewriter::getAdamFileName(const char* basisfilename)
{
	string ret(basisfilename);
	ret += ".adam";
	return ret;
}

void adamfilewriter::writeAdamFile(FILE* f, vector<plumbingpiece>& pieces)
{
	fprintf(f, "var plumb={\n");
	fprintf(f, "\"version\": 1,\n");
	fprintf(f, "\"type\": \"PLUMB\",\n");
	fprintf(f, "\"plumbs\": [\n");

	for(size_t i=0; i<pieces.size(); i++)
	{
		string msg = pieces[i].toString();
		if(i>0)
			fprintf(f,",");
		fprintf(f, "%s\n", msg.c_str());
	}

	fprintf(f, "]}");
}
