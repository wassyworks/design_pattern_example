#ifndef XML_EXPORTER_H
#define XML_EXPORTER_H
#include <sstream>
#include <string>
namespace adapter {
	class XmlExporter {
	public:
		std::string ToXml(const std::string& message) const {
			std::ostringstream oss;
			oss << "exported to xml ... " << message;
			return oss.str();
		}
	};
}

#endif // XML_EXPORTER_H