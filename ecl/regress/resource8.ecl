/*##############################################################################

    Copyright (C) 2011 HPCC Systems.

    All rights reserved. This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
############################################################################## */

__set_debug_option__('optimizeDiskRead',0);

baseRecord :=
            RECORD
unsigned8       id;
string20        surname;
string30        forename;
unsigned8       filepos{virtual(fileposition)}
            END;

baseTable1 := DATASET('base', baseRecord, THOR);
baseTable2 := DATASET('base', baseRecord, THOR);

baseRecord t(baseRecord l) :=
    TRANSFORM
        SELF := l;
    END;

//-------------------------------------------

x1 := baseTable1(surname <> 'Hawthorn');
x2 := baseTable2(surname <> 'Drimbad');

y1 := x1 + x2;
y2 := x2 + x1;

z := JOIN(y1, y2, LEFT.forename = RIGHT.forename, t(LEFT));

output(z,,'out.d00');

