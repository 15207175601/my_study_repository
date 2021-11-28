#include <istream>

namespace MyLib {
	double readAndProcessSum(std::istream& strm){
		using std::ios;
		double value, sum;

		ios::iostate oldExceptions = strm.exceptions();

		strm.exceptions(ios::failbit | ios::badbit);

		try {
			sum = 0;
			while (strm >> value) {
				sum += value;
			}
		}
		catch (...) {
			if (!strm.eof()) {
				strm.exceptions(oldExceptions);
				throw;
			}
		}

		strm.exceptions(oldExceptions);
		return sum;
	}
}