#include <stdio.h>
#include <iostream>
#include <string>
#include <time.h>
#include <sys/time.h>
#include <list>

#include "../prefiltering/Prefiltering.h"
#include "../alignment/Alignment.h"
#include "../clustering/Clustering.h"

extern "C" {
#include "ffindex.h"
#include "ffutil.h"
}

ffindex_index_t* openIndex(const char* indexFileName);

std::string runStep(std::string inDBData, std::string inDBWorkingIndex, std::string targetDBData, std::string targetDBIndex, std::string tmpDir,
        std::string scoringMatrixFile, int maxSeqLen, int seqType,
        int kmerSize, int alphabetSize, size_t maxResListLen, int split, int skip, bool aaBiasCorrection, float zscoreThr, float sensitivity,
        double evalThr, double covThr, float seqIdThr, int maxRejects,
        int step_num, int restart, bool search, std::list<std::string>* tmpFiles);

void copy(std::string inFile, std::string outFile);

float getZscoreForSensitivity (float sensitivity);

void deleteTmpFiles(std::list<std::string>* tmpFiles);

int omp_thread_count();
