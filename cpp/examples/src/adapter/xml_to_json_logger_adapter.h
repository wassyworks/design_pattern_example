#ifndef XML_TO_JSON_LOGGER_ADAPTER_H
#define XML_TO_JSON_LOGGER_ADAPTER_H
#include "logger.h"
#include "json_exporter.h"
namespace adapter {
	// Loggerがxml形式ではなく、json形式でログ出力するように変えるオブジェクトアダプター
	// ここではLoggerのインターフェイスを変えずに動作を変更している
	class XmlToJsonLoggerAdapter : public Logger {
	public:
		void Logging(const std::string& message) const override
		{
			std::cout << json_exporter_.ToJson(message) << std::endl;
		}
	private:
		JsonExporter json_exporter_;
	};
};

#endif //XML_TO_JSON_LOGGER_ADAPTER_H