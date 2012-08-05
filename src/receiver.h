/* 
 * File:   receiver.h
 * Author: zhenka
 *
 * Created on 6 Август 2012 г., 0:29
 */

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include <event2/event.h>
#include <event2/buffer.h>
#include <event2/http.h>
#include <event2/http_struct.h>

#ifndef RECEIVER_H
#define	RECEIVER_H

class receiver
{
public:

    struct download_context
    {
        struct evhttp_uri *uri;
        struct event_base *base;
        struct evhttp_connection *cn;
        struct evhttp_request *req;

        struct evbuffer *buffer;
        int ok;
    };

    receiver( std::string uri );
    ~receiver( );
private:

} ;

#ifdef NONONO




int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("usage: %s example.com/\n", argv[0]);
		return 1;
	}

	struct evbuffer *data = download_url(argv[1]);

	printf("got %d bytes\n", data ? evbuffer_get_length(data) : -1);

	if (data)
	{
		const char *joined = evbuffer_pullup(data, -1);
		printf("data itself:\n====================\n");
		write(1, joined, evbuffer_get_length(data));
		printf("\n====================\n");

		evbuffer_free(data);
	}

	return 0;
}


#endif

#endif	/* RECEIVER_H */

