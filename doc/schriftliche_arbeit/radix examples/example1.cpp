// 
#define RADIXBYTE(num, pass) static_cast<std::uint8_t>((num >> (pass << 3)))
// 
for(std::uint64_t i = 0; i < vector.size(); ++i){
	counters.at(256 * 0 + RADIXBYTE(vector.at(i), 0))++;
	counters.at(256 * 1 + RADIXBYTE(vector.at(i), 1))++;
	counters.at(256 * 2 + RADIXBYTE(vector.at(i), 2))++;
	counters.at(256 * 3 + RADIXBYTE(vector.at(i), 3))++;
}
