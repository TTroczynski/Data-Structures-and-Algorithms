#include "VoteOn.h"

int  VoteOn(void* Instances[], int nInstances, int nSize)
{

	void* pCurrent = NULL;
	void* pNext = NULL;

	int currentBestIndex = -1;
	int currentMostMatches = 0;
	int currentInstance = 0;
	int nextInstance = currentInstance + 1;
	int previousBestIndex = -1;
	int previousMostMatches = 0;
	int matchCount = 1;
	int matchesMin = nInstances / 2;

	if (matchesMin * 2 < nInstances) {
		matchesMin++;
	}

	pCurrent = Instances[currentInstance];

	while (currentInstance < (nInstances - 1)) {

		pNext = Instances[nextInstance];

		if (!memcmp(pCurrent, pNext, nSize)) {
			matchCount++;
		}

		if (nextInstance == nInstances - 1) {
			if (matchCount >= currentMostMatches) {
				previousMostMatches = currentMostMatches;
				previousBestIndex = currentBestIndex;
				currentMostMatches = matchCount;
				currentBestIndex = currentInstance;
			}
			currentInstance++;
			pCurrent = Instances[currentInstance];
			nextInstance = currentInstance;
			matchCount = 1;
		}
		nextInstance++;
	}

	if ((previousMostMatches == currentMostMatches) || currentMostMatches <= 1) {
		return -1;
	}
	else {
		return currentBestIndex;
	}

	return -1;
}