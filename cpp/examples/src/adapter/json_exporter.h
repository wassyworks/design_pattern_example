#ifndef JSON_EXPORTER_H
#define JSON_EXPORTER_H
#include <sstream>
#include <string>
namespace adapter {
	class JsonExporter
	{
	public:
		std::string ToJson(const std::string& message) const {
			std::ostringstream oss;
			oss << "exported to json ... " << message;
			return oss.str();
		}
	};
}

#endif // JSON_EXPORTER_H
