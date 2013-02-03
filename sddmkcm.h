/*
 *   Copyright 2013 by Reza Fatahilah Shah <rshah0385@kireihana.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License as
 *   published by the Free Software Foundation; either version 2, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#ifndef SDDMKCM_H
#define SDDMKCM_H

#include <KCModule>

class ThemeConfig;

class SddmKcm : public KCModule
{
    Q_OBJECT
public:
    explicit SddmKcm(QWidget *parent, const QVariantList &args);
    ~SddmKcm();

public slots:
    void save();

private:
    void prepareUi();
    
private:
    ThemeConfig *mThemeConfig;
};

#endif // SDDMKCM_H