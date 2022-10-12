/*
 * Copyright (C) 2021 CutefishOS Team.
 *
 * Author:     cutefish <cutefishos@foxmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef THEMEMANAGER_H
#define THEMEMANAGER_H

#include <QObject>
#include <QFont>
#include <QColor>

#define ACCENTCOLOR_NATSKYBLUE   0
#define ACCENTCOLOR_LIGHTBLUE    1
#define ACCENTCOLOR_SKYBLUE  2
#define ACCENTCOLOR_GRAPE 3
#define ACCENTCOLOR_WINERED   4
#define ACCENTCOLOR_ORANGE 5
#define ACCENTCOLOR_YELLOW   6

class ThemeManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool darkMode READ darkMode NOTIFY darkModeChanged)
    Q_PROPERTY(QColor accentColor READ accentColor NOTIFY accentColorChanged)
    Q_PROPERTY(QColor natskyblueColor READ natskyblueColor CONSTANT)
    Q_PROPERTY(QColor lightblueColor READ lightblueColor CONSTANT)
    Q_PROPERTY(QColor skyblueColor READ skyblueColor CONSTANT)
    Q_PROPERTY(QColor grapeColor READ grapeColor CONSTANT)
    Q_PROPERTY(QColor wineredColor READ wineredColor CONSTANT)
    Q_PROPERTY(QColor orangeColor READ orangeColor CONSTANT)
    Q_PROPERTY(QColor yellowColor READ yellowColor CONSTANT)
    Q_PROPERTY(qreal devicePixelRatio READ devicePixelRatio CONSTANT)
    Q_PROPERTY(qreal fontSize READ fontSize NOTIFY fontSizeChanged)
    Q_PROPERTY(QString fontFamily READ fontFamily NOTIFY fontFamilyChanged)

public:
    explicit ThemeManager(QObject *parent = nullptr);

    qreal devicePixelRatio() const;

    bool darkMode() { return m_darkMode; }
    QColor accentColor() { return m_accentColor; }

    qreal fontSize() { return m_fontSize; }
    QString fontFamily() { return m_fontFamily; }

    QColor natskyblueColor() { return m_natskyblueColor; }
    QColor lightblueColor() { return m_lightblueColor; }
    QColor skyblueColor() { return m_skyblueColor; }
    QColor grapeColor() { return m_grapeColor; }
    QColor wineredColor() { return m_wineredColor; }
    QColor orangeColor() { return m_orangeColor; }
    QColor yellowColor() { return m_yellowColor; }

signals:
    void darkModeChanged();
    void accentColorChanged();
    void fontSizeChanged();
    void fontFamilyChanged();

private slots:
    void initData();
    void initDBusSignals();
    void onDBusDarkModeChanged(bool darkMode);
    void onDBusAccentColorChanged(int accentColorID);
    void onDBusFontSizeChanged();
    void onDBusFontFamilyChanged();

private:
    void setAccentColor(int accentColorID);

private:
    bool m_darkMode;
    int m_accentColorIndex;

    QColor m_natskyblueColor   = QColor(86,  208, 102);   // #3385FF
    QColor m_lightblueColor    = QColor(86,  208,  208);   // #FF5C6D
    QColor m_skyblueColor  = QColor(60,  144, 191);    // #35BF56
    QColor m_grapeColor = QColor(203, 111, 235);   // #8266FF
    QColor m_wineredColor   = QColor(208, 86, 86);   // #CA64AC
    QColor m_orangeColor = QColor(239, 149, 66);    // #FEA042
    QColor m_yellowColor   = QColor(111, 240, 170);     // #4F596B

    QColor m_accentColor;
    qreal m_fontSize;
    QString m_fontFamily;
};

#endif // THEMEMANAGER_H
