#ifndef WINDOWCOMMON_H
#define WINDOWCOMMON_H

#include <QString>
#include <QRegExp>

// Note: Single backslash is escaped with a second backslash
static const QRegExp ASCII_ALPHA_WHITE_SPACE_REGEX("[A-Za-z\\s]+");
static const QRegExp ASCII_ALPHA_LOWER_REGEX("[a-z]+");



static const QString CAESER_LABLE_TEXT = "Rotation Factor: ";

static const QStringList CAESAR_SHIFTS =
{
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "11",
    "12",
    "13",
    "14",
    "15",
    "16",
    "17",
    "18",
    "19",
    "20",
    "21",
    "22",
    "23",
    "24",
    "25",
    "26"
};

#endif // WINDOWCOMMON_H
