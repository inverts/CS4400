struct s1 {
  signed char f0;
  unsigned long long f1;
  unsigned char f2;
  unsigned long long f3;
  short f4;
  long long f5;
};

struct s2 {
  unsigned int f0;
  unsigned long f1;
  unsigned long f2;
  unsigned int f3;
  unsigned long long f4;
  unsigned int f5;
};

#pragma pack (1)
struct s2_packed {
  unsigned int f0;
  unsigned long f1;
  unsigned long f2;
  unsigned int f3;
  unsigned long long f4;
  unsigned int f5;
};
#pragma pack ()

struct s3 {
  unsigned long long f0;
  signed char f1;
  long long f2;
  signed char f3;
  unsigned int f4;
  unsigned short f5;
};

struct s3_bitfield {
  unsigned long long f0 : 29;
  signed char f1 : 7;
  long long f2 : 36;
  signed char f3 : 3;
  unsigned int f4 : 7;
  unsigned short f5 : 16;
};

