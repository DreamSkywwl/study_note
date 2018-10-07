#include "iostream"

void arfupt_test();
const double * f1(const double ar[],int n);
const double * f2(const double [],int);
const double * f3(const double *,int);

void arfupt_test() {
  double av[3] = {1112.3, 1542.6, 2227.9};

  // pointer to a function
  const double* (*p1)(const double*, int) = f1;

  auto p2 = f2;  // c++11 automatic type deduction
  // pre-C++11 can use the following code instead
  // const double *(*p2)(const double *,int) = f2;

  std::cout << "Useing pointers to functions:\n";
  std::cout << " Address Value\n";
  std::cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << std::endl;
  std::cout << p2(av, 3) << ": " << *p2(av, 3) << std::endl;

  // pa an array of pointers
  // auto doesn't work with list initialization
  const double* (*pa[3])(const double*, int) = {f1, f2, f3};

  // but it does work for initialization to a single value
  // pb a pointer to first element of pa
  auto pb = pa;
  // pre-C++11 can use the following code instead
  // const double *(**pb)(const double *,int) = pa;

  std::cout << "\nUsing an array of pointers to functions:\n";
  std::cout << "Address Value\n";
  for (int i = 0; i < 3; i++) {
    std::cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << std::endl;
  }

  // what about a pointer to an array of function pointers
  std::cout << "\nUsing pointers to an array of function pointers\n";
  std::cout << " Address Value\n";

  // easy way to declare pc
  auto pc = &pa;
  // pre-C++11 can use the following code instead
  // const double *(*(*pc)[3])(const double *,int) = &pa;
  std::cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << std::endl;
  // hard way to declare pd
  const double* (*(*pd)[3])(const double*, int) = &pa;

  // store return value in pdb
  const double* pdb = (*pd)[1](av, 3);
  std::cout << pdb << ": " << *pdb << std::endl;

  // alternative notation
  std::cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << std::endl;
}

const double* f1(const double ar[], int n) {
  return ar;
}

const double* f2(const double ar[], int n) {
  return ar + 1;
}

const double* f3(const double* ar, int n) {
  return ar + 2;
}

//########################
//#print
//Useing pointers to functions:
// Address Value
//0x7ffeefbff550: 1112.3
//0x7ffeefbff558: 1542.6
//
//Using an array of pointers to functions:
//Address Value
//0x7ffeefbff550: 1112.3
//0x7ffeefbff558: 1542.6
//0x7ffeefbff560: 2227.9
//
//Using pointers to an array of function pointers
// Address Value
//0x7ffeefbff550: 1112.3
//0x7ffeefbff558: 1542.6
//0x7ffeefbff560: 2227.9
//Program ended with exit code: 0
