#include <sweph.h>

static std::vector<std::pair<int, std::string>> args = {
	{ 1, "Expecting 1 arguments: path" },
	{ STRING, "Argument 1 should be a string - path to ephemeris files" }
};

void sweph_set_ephe_path(const Napi::CallbackInfo& info) {
	if(!sweph_type_check(args, info)) {
		return;
	}
	swe_set_ephe_path(info[0].IsString() ? (char*)info[0].As<Napi::String>().Utf8Value().c_str() : NULL);
	return;
}
