//
// Created by michal on 16/06/19.
//

#ifndef ALGOS_COMPRESSION_RUN_LENGTH_H
#define ALGOS_COMPRESSION_RUN_LENGTH_H


#include "../data_structures/bit_stream.h"

int Count(BitStream* bit_stream, int max_count, bool which_bit);

BitStream compress(BitStream* bit_stream);

BitStream expand(BitStream* bit_stream);

#endif //ALGOS_COMPRESSION_RUN_LENGTH_H
