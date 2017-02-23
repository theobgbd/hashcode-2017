struct ret
{
	int nbVideo;
	int nbEndpoint;
	int nbRequest;
	int nbCache;
	int capacityCache;
	double** latencyCache;
	double* latencyData;
	double** request;
};
typedef struct ret ret;


ret *ReadingFile();
