/*
	*
	* Copyright 2020 Britanicus <marcusbritanicus@gmail.com>
	*
	* This file is a part of QtGreet project (https://gitlab.com/marcusbritanicus/QtGreet)
	*

	*
	* This program is free software; you can redistribute it and/or modify
	* it under the terms of the GNU General Public License as published by
	* the Free Software Foundation; either version 3 of the License, or
	* (at your option) any later version.
	*

	*
	* This program is distributed in the hope that it will be useful,
	* but WITHOUT ANY WARRANTY; without even the implied warranty of
	* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	* GNU General Public License for more details.
	*

	*
	* You should have received a copy of the GNU General Public License
	* along with this program; if not, write to the Free Software
	* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
	* MA 02110-1301, USA.
	*
*/

// Local Headers
#include "Global.hpp"
#include "QtGreet.hpp"
#include "LayoutManager.hpp"

QSize mScreenSize;
QSettings *sett;
QSettings *users;

int main( int argc, char **argv ) {

	QCoreApplication::setAttribute( Qt::AA_EnableHighDpiScaling );

	QApplication app( argc, argv );

	/** Screen Size */
	mScreenSize = app.primaryScreen()->size();

	/** Settings Objects */
	sett = new QSettings( "/etc/qtgreet/config.ini", QSettings::IniFormat );
	users = new QSettings( "/etc/qtgreet/users.conf", QSettings::IniFormat );

	QtGreet::UI *qtgreet = new QtGreet::UI();
	qtgreet->showFullScreen();

	// QtGreet::Layout *lyt = new QtGreet::Layout();
    // lyt->generateLayout( argv[ 1 ] );

	return app.exec();
};
