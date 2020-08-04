//#ifndef CONFIGURATION_LOADER_HPP
//#define CONFIGURATION_LOADER_HPP
//
//#include <sstream>
//#include <unordered_map>
//
//enum ConvertType {
//    TYPE_DOUBLE,
//    TYPE_INT,
//    TYPE_STRING
//};
//
//
//
//class Value {
//
//public:
//    virtual std::string toString() = 0;
//};
//
//class DoubleValue: public Value {
//
//
//public: 
//    
//    DoubleValue(double val) : val_(val) {
//
//    };
//
//    double val_;
//
//    std::string toString() override {
//        return "double";
//    }
//};
//
//
//std::unordered_map<std::string, ConvertType> TYPES = {
//    {"a", TYPE_DOUBLE},
//    {"b", TYPE_INT}
//};
//
//
//class Converter {
//public:
//    virtual Value convert(std::istringstream& ss) = 0;
//};
//
//class DoubleConverter: public Converter {
//    DoubleValue convert(std::istringstream& ss) override {
//
//        double val;
//        if (ss >> val) {
//            return DoubleValue{val};
//        }
//        else {
//            throw new std::exception("Couldn't parse as double value");
//        }
//    }
//};
//
////class IntConverter : public Converter {
////    Value convert(std::istringstream& ss) override {
////
////        int val;
////        if (ss >> val) {
////            return Value{};
////        }
////        else {
////            throw new std::exception("Couldn't parse as int value");
////        }
////    }
////};
////
////class StringConverter : public Converter {
////    Value convert(std::istringstream& ss) override {
////
////        std::string val;
////        if (ss >> val) {
////            return Value{};
////        }
////        else {
////            throw new std::exception("Couldn't parse as string value");
////        }
////    }
////};
//
//class ConfigurationLoader {
//
//    void load(std::istream& stream) {
//
//        Converter* converters[3];
//        converters[TYPE_DOUBLE] = new DoubleConverter();
//
//
//        std::string line, header;
//
//        while (std::getline(stream, line)) {
//
//            std::istringstream string_stream;
//            string_stream.clear();
//            string_stream.str(line);
//
//
//            if (string_stream >> header) {
//
//                auto it = TYPES.find(header);
//
//                if (it != TYPES.end()) {
//
//                    std::cout << converters[it->second]->convert(string_stream) << std::endl;
//                }
//                else {
//                    auto message = "Header not defined: " + header;
//                    throw new std::exception(message.c_str());
//                }
//            }
//            else {
//                throw new std::exception("Failed to read header");
//            }
//        }
//    }
//};
//
////IDEE FÜR REGELN -> einfach die regel als kompletten string laden -> dann hat man nur einen Wert -> diesen Wert kann mann dann später in einer anderen FUnktionn trennen wenn man die Produktionen dem Lsystem zuweist
//#endif