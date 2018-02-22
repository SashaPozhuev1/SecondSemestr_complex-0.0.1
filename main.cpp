#include <iostream>
#include <sstream>

struct complex_t {
private:
	float real;
	float imag;
public:
	complex_t() {
		real = 0.0f;
		imag = 0.0f;
	}

	complex_t add( complex_t other ) const {
		complex_t result;
		result.real = this->real + other.real;
		result.imag = this->imag + other.imag;
		return result;
	}
	complex_t sub( complex_t other ) const {
		complex_t result;
		result.real = this->real - other.real;
		result.imag = this->imag - other.imag;
		return result;
	}
	complex_t mul( complex_t other ) const {
		complex_t result;
		result.real = this->real * other.real - this->imag * other.imag;
		result.imag = this->imag * other.real + this->real * other.imag;
		return result;
	}
	complex_t div( complex_t other ) const {
		complex_t result;
		result.real = ( this->real * other.real + this->imag * other.imag ) / ( other.real * other.real + other.imag * other.imag );
		result.imag = ( this->imag * other.real - this->real * other.imag ) / ( other.real * other.real + other.imag * other.imag );
		return result;
	}

	std::istream & read( std::istream & stream ) {
		char symb;
		if ( stream >> symb && symb == '(' &&
			stream >> real &&
			stream >> symb && symb == ',' &&
			stream >> imag &&
			stream >> symb && symb == ')' ) {

		}
		return stream;
	}
	std::ostream & write( std::ostream & stream ) const {
		return stream << '(' << real << ", " << imag << ')';
	}

	~complex_t() { }
};

void error() {
	std::cout << "An error has occured while reading input data\n";
}

int main()
{
	complex_t complex1;
	complex_t complex2;

	std::string line;
	getline( std::cin, line );
	std::istringstream stream( line );
	char symb;
	
	if ( complex1.read( stream ) && stream >> symb && complex2.read( stream ) ) {
		complex_t result;

		if ( symb == '+' ) {
			result = complex1.add(complex2);
			result.write(std::cout);
		}
		else if ( symb == '-' ) {
			result = complex1.sub( complex2 );
			result.write( std::cout );
		}
		else if ( symb == '*' ) {
			result = complex1.mul( complex2 );
			result.write( std::cout );
		}
		else if ( symb == '/' ) {
			result = complex1.div( complex2 );
			result.write( std::cout );
		}
		else {
			error();
		}

		result.~complex_t();
	}
	else {
		error();
	}

	std::cin.get();
	complex1.~complex_t();
	complex2.~complex_t();
    return 0;
}
