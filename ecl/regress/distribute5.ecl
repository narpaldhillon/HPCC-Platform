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

namesRecord :=
            RECORD
integer2        age := 25;
string20        surname;
string10        forename;
            END;

namesTable := dataset('x',namesRecord,FLAT);


inf := distribute(namesTable, hash32(forename));

j5 := join(inf,inf,left.forename[1..*]=right.forename[1..*] and left.forename[length(trim(left.forename))-3..] = right.forename[length(trim(right.forename))-3..] and (left.age * right.age < 880),atmost(left.forename[1..*]=right.forename[1..*] and left.forename[length(trim(left.forename))-3..] = right.forename[length(trim(right.forename))-3..],1000),hash);
output(j5);

