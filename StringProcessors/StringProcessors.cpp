#include "StringProcessors.h"
char* addZeros(char* str, int n)
{
	int oldSize = strlen(str);
	int begin = 0, end = 0, wordSize = 0, resIter = 0, difSize = 0, size = oldSize;
	char* res = NULL;
	for (int i = 0; i < oldSize; i++) {
		if (str[i] == ' ' || str[i+1] == '\0') {
			begin = end;
			end = i;
			if (str[i + 1] == '\0')
			{
				end++;
			}
			if (i != 0) {
				begin++;
			}
			wordSize = end - begin;
			if (wordSize < n) {
				size += n - wordSize;
			}
		}
	}

	res = (char*)calloc(size + 1, sizeof(char));
	resIter = size - 1;
	res[size] = '\0';
	end = oldSize - 1;
	for (int i = oldSize - 1; i >= 0; i--) {
		if (str[i] == ' ' || i == 0) {
			begin = end;
			end = i;
			if (i == 0)
			{
				end--;
			}
			if (begin != oldSize - 1) {
				begin--;
			}
			wordSize = begin - end;
			if (wordSize < n) {
				difSize = n - wordSize;
			}
			if (i == 0)
			{
				res[resIter] = str[i];
				resIter--;
			}
			for (int j = 0; j < difSize; j++)
			{
				res[resIter] = '0';
				resIter--;
			}
			if (i != 0)
			{
				res[resIter] = ' ';
				resIter--;
			}
			difSize = 0;
		}
		else
		{
			res[resIter] = str[i];
			resIter--;
		}	
	}

	return res;
}