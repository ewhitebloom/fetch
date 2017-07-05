#ifndef EXCEPTION
#define EXCEPTION

#include <exception>
#include <iostream>
#include <map>

using namespace std;

class FetchException : public exception {
  char * what () const throw () {
      return "Something went wrong!";
   }
};

class UnSupportedProtocol : public FetchException {
  char * what () const throw () {
      return "The URL you passed to fetch is using a protocol that fetch doesn't support";
   }
};

class URLMalformed : public FetchException {
  char * what () const throw () {
      return "The URL passed in was not properly formatted";
   }
};

class CouldNotResolveProxy : public FetchException {
  char * what () const throw () {
      return "Couldn't resolve proxy. The given proxy host could not be resolved.";
   }
};

class CouldNotResolveHost : public FetchException {
  char * what () const throw () {
      return "Fetch couldn't resolve the given host.";
   }
};

class FailedToConnect : public FetchException {
  char * what () const throw () {
      return "Fetch failed to connect to the host or proxy";
   }
};

class FTPException : public FetchException {
  char * what () const throw () {
      return "There's been an error processing this FTP request.";
   }
};

class FTPWeirdServerReply : public FTPException {
  char * what () const throw () {
      return "The server sent Fetch data that it couldn't parse";
   }
};

class RemoteAccessDenied : public FTPException {
  char * what () const throw () {
      return "We were denied access to the resource given in the URL";
   }
};

class FTPAcceptFailed : public FTPException {
  char * what () const throw () {
      return "We were denied access to the resource given in the URL";
   }
};

class HTTP2Error : public FetchException {
  char * what () const throw () {
      return "A problem was detected in the HTTP2 framing layer. This is somewhat generic and can be one out of several problems, see the error buffer for details.";
   }
};

class HTTPReturnedError : public FetchException {
  char * what () const throw () {
      return "This HTTP request returned a status code greater than 400";
   }
};

class WriteError : public FetchException {
  char * what () const throw () {
      return "An error occurred when writing received data to a local file, or an error was returned to Fetch from a write callback.";
   }
};

class ReadError : public FetchException {
  char * what () const throw () {
      return "There was a problem reading a local file or an error returned by the read callback.";
   }
};

class TimeOut : public FetchException {
  char * what () const throw () {
      return "The request timed out";
   }
};

class RangeError : public FetchException {
  char * what () const throw () {
      return "The server does not support or request range request";
   }
};

class PostError : public FetchException {
  char * what () const throw () {
      return "This is an odd error that mainly occurs due to internal confusion.";
   }
};

class SSLConnectError : public FetchException {
  char * what () const throw () {
      return "A problem occurred somewhere in the SSL/TLS handshake.";
   }
};

class FileCouldntReadFile : public FetchException {
  char * what () const throw () {
      return "A file given with FILE:// couldn't be opened.";
   }
};

class AbortedByCallback : public FetchException {
  char * what () const throw () {
      return "Aborted by callback. A callback returned abort to libcurl.";
   }
};


class InterfaceFailed : public FetchException {
  char * what () const throw () {
      return "Interface error. A specified outgoing interface could not be used.";
   }
};

class TooManyRedirects : public FetchException {
  char * what () const throw () {
      return "Too many redirects.";
   }
};

class NothingReturned : public FetchException {
  char * what () const throw () {
      return "The server returned nothing to fetch.";
   }
};

class SSLEngineNotFound : public FetchException {
  char * what () const throw () {
      return "The specified crypto engine wasn't found.";
   }
};

class SSLEngineSetFailed : public FetchException {
  char * what () const throw () {
      return "Failed setting the selected SSL crypto engine as default!";
   }
};

class SendError : public FetchException {
  char * what () const throw () {
      return "Failed sending network data.";
   }
};

class RECVError : public FetchException {
  char * what () const throw () {
      return "Failure with receiving network data.";
   }
};

class SSLCertProblem : public FetchException {
  char * what () const throw () {
      return "problem with the local client certificate.";
   }
};

class SSLCipher : public FetchException {
  char * what () const throw () {
      return "Couldn't use specified cipher.";
   }
};

class SSLCaCert : public FetchException {
  char * what () const throw () {
      return "Peer certificate cannot be authenticated with known CA certificates.";
   }
};

class BadContentEncoding : public FetchException {
  char * what () const throw () {
      return "Unrecognized transfer encoding.";
   }
};

class SendFailRewind : public FetchException {
  char * what () const throw () {
      return "When doing a send operation fetch had to rewind the data to retransmit, but the rewinding operation failed.";
   }
};

class SSLEngineInitfailed : public FetchException {
  char * what () const throw () {
      return "Initiating the SSL Engine failed.";
   }
};

class CharacterConversionFailed : public FetchException {
  char * what () const throw () {
      return "Character conversion failed.";
   }
};

class SSL_CACERT_BADFILE : public FetchException {
  char * what () const throw () {
      return "Problem with reading the SSL CA cert (path? access rights?)";
   }
};

class SSLShutdownFailed : public FetchException {
  char * what () const throw () {
      return "Failed to shut down the SSL connection.";
   }
};

class SSLCrlBadFile : public FetchException {
  char * what () const throw () {
      return "Failed to load CRL file (Added in 7.19.0)";
   }
};

class SSLIssuerError : public FetchException {
  char * what () const throw () {
      return "Issuer check failed (Added in 7.19.0)";
   }
};

class SSLPinnedPubKeyNotMatch : public FetchException {
  char * what () const throw () {
      return "Failed to match the pinned key specified with CURLOPT_PINNEDPUBLICKEY";
   }
};

class SSLInvalidCertStatus : public FetchException {
  char * what () const throw () {
      return "Status returned failure when asked with CURLOPT_SSL_VERIFYSTATUS.";
   }
};

class HTTP2Stream : public FetchException {
  char * what () const throw () {
      return "Stream error in the HTTP/2 framing layer.";
  }
};

void raiseCurlCode(int curlCode) {
  if (curlCode == 0) return;
  switch (curlCode) {
    case 1:
      throw UnSupportedProtocol();
    case 3:
      throw URLMalformed();
    case 5:
      throw CouldNotResolveProxy();
    case 6:
      throw CouldNotResolveHost();
    case 7:
      throw FailedToConnect();
    case 9:
      throw RemoteAccessDenied();
    case 16:
      throw HTTP2Error();
    case 22:
      throw HTTPReturnedError();
    case 23:
      throw WriteError();
    case 26:
      throw ReadError();
    case 28:
      throw TimeOut();
    case 33:
      throw RangeError();
    case 35:
      throw SSLConnectError();
    case 37:
      throw FileCouldntReadFile();
    case 42:
      throw AbortedByCallback();
    case 45:
      throw InterfaceFailed();
    case 47:
      throw TooManyRedirects();
    case 52:
      throw NothingReturned();
    case 53:
      throw SSLEngineNotFound();
    case 54:
      throw SSLEngineSetFailed();
    case 55:
      throw SendError();
    case 56:
      throw RECVError();
    case 58:
      throw SSLCertProblem();
    case 59:
      throw SSLCipher();
    case 60:
      throw SSLCaCert();
    case 61:
      throw BadContentEncoding();
    case 65:
      throw SendFailRewind();
    case 66:
      throw SSLEngineInitfailed();
    case 75:
      throw CharacterConversionFailed();
    case 77:
      throw SSL_CACERT_BADFILE();
    case 80:
      throw SSLShutdownFailed();
    case 82:
      throw SSLCrlBadFile();
    case 83:
      throw SSLIssuerError();
    case 90:
      throw SSLPinnedPubKeyNotMatch();
    case 91:
      throw SSLInvalidCertStatus();
    case 92:
      throw HTTP2Stream();
    default:
      throw FetchException();
  }
}

#endif
