#ifndef ALGOS_MISC_READ_LAST_N_H_
#define ALGOS_MISC_READ_LAST_N_H_

#include <string>
#include <fstream>
#include <iostream>


template <int N>
/**
 * @brief alfo to read last N line from a file
 *
 * @param file_name to read
 */
void ReadLastN(const std::string &file_name){
  std::string last_n[N];
  int current = 0;
  std::ifstream file(file_name);
  
  while (file.peek() != EOF){
    std::getline(file, last_n[current % N]);
    current = (current + 1) % N;
  }

  for (int i = 0; i < N; i++){
    std::cout << last_n[current] << std::endl;
    current = (current + 1) % N;
  }
}


#endif // ALGOS_MISC_READ_LAST_N_H_
