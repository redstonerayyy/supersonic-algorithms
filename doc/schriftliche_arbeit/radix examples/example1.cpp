// C++ Makro, um eines der 4 bytes eines positiven 
// Integers zu extrahieren und als Byte zu speichern
#define RADIXBYTE(num, pass) static_cast<std::uint8_t>((num >> (pass << 3)))
// Berechnung für jede zu sortierende Zahl
for(std::uint64_t i = 0; i < vector.size(); ++i){
	// Zähler des Vorkommens der Bytes erhöhen
	counters.at(256 * 0 + RADIXBYTE(vector.at(i), 0))++;
	counters.at(256 * 1 + RADIXBYTE(vector.at(i), 1))++;
	counters.at(256 * 2 + RADIXBYTE(vector.at(i), 2))++;
	counters.at(256 * 3 + RADIXBYTE(vector.at(i), 3))++;
}



