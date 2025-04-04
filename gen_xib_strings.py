#!/usr/bin/env python
'''
  PocketSword - A frontend for viewing SWORD project modules on the iPhone and iPod Touch
	Copyright (C) 2008-2009 Ian Wagner
  
	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.
  
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
  
	You should have received a copy of the GNU General Public License along
	with this program; if not, write to the Free Software Foundation, Inc.,
	51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
	
	This file is used to generate localized strings files for all xib files.
	
	NOTE: You should NEVER EDIT ANY XIB FILE EXCEPT THE ENGLISH ONE!!! The other xib's are
	generated from the objects in the English one. Localizations are generated from the strings in
	the strings files.
'''
import sys
import os

if len(sys.argv) < 2:
  print 'Usage: gen_xib_strings.py [-p] path'
  print '  path  The directory from which the xib files may be reached'
  print '  -p    Prompt to overwrite existing files (default to skip existing strings files)' 
  sys.exit(1)
elif not os.path.exists(sys.argv[-1]):
  print 'path "%s" does not exist!' % sys.argv[-1]
  sys.exit(1)

for root, dirs, files in os.walk(sys.argv[-1]):
  for file in files:
    if len(file) > 4 and file[-4:] == '.xib':
      basename = os.path.join(root, file)[:-4]
      if os.path.exists(basename + '.strings'):
        if '-p' not in sys.argv:
          continue
          
        choice = raw_input('File: %s.strings exists. Overwrite (Y/N)? ' % basename)
        if choice.upper() != 'Y':
          print 'Not writing strings for %s.xib' % basename
          continue
      cmd = 'ibtool --generate-strings-file "%s.strings" "%s.xib"' % (basename, basename)
      if os.system(cmd) != 0:
        print 'failed to execute command: %s' % cmd