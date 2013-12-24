/* Copyright (C) 2013 CompleteDB LLC.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with PubSubSQL.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PUBSUBSQLSVC_PIPE_H
#define PUBSUBSQLSVC_PIPE_H

#include <Windows.h>
#include <string>

class pipe {
public:
	pipe();
	~pipe();
	bool ok();	
	const char* readLine();
	void writeLine(const char*);
	
private:
	FILE* toFileFromHandle(HANDLE handle, const char* fileOpenMode);

	static const unsigned BUFFER_SIZE = 4096;
	bool valid;
	SECURITY_ATTRIBUTES securityAttributes;
	FILE* readFile;
	FILE* writeFile;
	HANDLE pipeHandle;
	HANDLE readHandle;
	HANDLE writeHandle;
	char buffer[BUFFER_SIZE + 1];

};

#endif //PUBSUBSQLSVC_PIPE_H