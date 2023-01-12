for(std::uint64_t i = 0; i < vectorizedruns; i += 4){
	
	__m256i_u values = _mm256_setr_epi32(
		0U, vector.at(i), 
		0U, vector.at(i + 1), 
		0U, vector.at(i + 2), 0U, 
		vector.at(i + 3));
	__m256i_u shufflevector = _mm256_setr_epi8(
		0b00000111, 0b10000000, 0b00000110, 0b10000000,
		0b00000101, 0b10000000, 0b00000100, 0b10000000,
		0b00001111, 0b10000000, 0b00001110, 0b10000000,
		0b00001101, 0b10000000, 0b00001100, 0b10000000,
		0b00000111, 0b10000000, 0b00000110, 0b10000000,
		0b00000101, 0b10000000, 0b00000100, 0b10000000,
		0b00001111, 0b10000000, 0b00001110, 0b10000000,
		0b00001101, 0b10000000, 0b00001100, 0b10000000
	);
	__m256i_u shuffled =  _mm256_shuffle_epi8(values, shufflevector);
	__m256i_u result = _mm256_adds_epu16(shuffled, passes);

	short *resultpointer = (short*)&result;
	for(std::uint8_t j = 0; j < 16; j++){
		counters.at((unsigned short)resultpointer[j])++;
	}
}
