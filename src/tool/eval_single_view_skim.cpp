#include "database/Dataset.hpp"
#include "common/Segment.hpp"
#include "common/util.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using std::vector;

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("usage: %s <database> <video_id> <skimming>\n", argv[0]);
    return -1;
  }

  Dataset set(argv[1]);
  FILE* ifile = fopen(argv[3], "r");
  int video_id = atoi(argv[2]);
  int offset = atoi(argv[4]);
  vector<Segment> skim;
  parseSingleViewSkim(ifile, set.getVideoInfo()[video_id].offset, skim);
  set.evaluateSingleViewSkim(skim, video_id);
}