class itemType {
public:
	string name;
	string manufacturer;
	int numdoor;
	itemType() {}
	itemType(string manfac, int door) {
		this->name = name;
		this->manufacturer = manfac;
		this->numdoor = door;
	}
	string getmanfac() {
		return this->manufacturer;
	}
};