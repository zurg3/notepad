#include <QString>
#include <QSysInfo>

constexpr auto app_version = "0.5.1";

constexpr auto app_version_major = 0;
constexpr auto app_version_minor = 5;
constexpr auto app_version_patch = 1;

constexpr auto app_build = "72";

const QString app_full_version = app_version + QString(" (") + app_build + QString(")") + QString(" ") + QSysInfo::buildCpuArchitecture();
