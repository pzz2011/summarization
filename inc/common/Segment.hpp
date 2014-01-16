#ifndef SEGMENT_H
#define SEGMENT_H

struct Segment
{
  int start;
  int end;
  int video_id;
  Segment(int _start, int _end, int _video_id):
      start(_start), end(_end), video_id(_video_id) {}
}

#endif
