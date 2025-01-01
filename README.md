# C/C++ library for CAN bus
Basic functions for modifying the CAN frame payload 

Example
```cpp
#define PAYLOAD_SIZE 8

uint8_t payload[PAYLOAD_SIZE];

bool test1()
{
	can_data_modify_bit(payload, 55, 1);
	can_data_modify_bit(payload, 48, 1);
	can_data_modify_bit(payload, 52, 1);
	can_data_modify_bit(payload, 55, 1);
	return payload[6] == 0x91 ? true : false;
}

bool test2()
{
	// change value to 0x2 at address 63 for Motorola format
	can_data_modify_value(payload, PAYLOAD_SIZE, 63, 6, 0x2, 1);
	return payload[7] == 0xFC ? true : false;
}

int main() {
	printf("%s: test1 \n", test1() ? "PASSED" : "FAILED");
	printf("%s: test2 \n", test2() ? "PASSED" : "FAILED");
}
```