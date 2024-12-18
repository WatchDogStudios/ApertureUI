/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 * SPDX-License-Identifier: curl
 *
 ***************************************************************************/
#include "tool_setup.h"
#include "tool_help.h"

/*
 * DO NOT edit tool_listhelp.c manually.
 * This source file is generated with the following command in an autotools
 * build:
 *
 * "make listhelp"
 */

const struct helptxt helptext[] = {
  {"    --abstract-unix-socket <path>",
   "Connect via abstract Unix domain socket",
   CURLHELP_CONNECTION},
  {"    --alt-svc <filename>",
   "Enable alt-svc with this cache file",
   CURLHELP_HTTP},
  {"    --anyauth",
   "Pick any authentication method",
   CURLHELP_HTTP | CURLHELP_PROXY | CURLHELP_AUTH},
  {"-a, --append",
   "Append to target file when uploading",
   CURLHELP_FTP | CURLHELP_SFTP},
  {"    --aws-sigv4 <provider1[:prvdr2[:reg[:srv]]]>",
   "AWS V4 signature auth",
   CURLHELP_AUTH | CURLHELP_HTTP},
  {"    --basic",
   "HTTP Basic Authentication",
   CURLHELP_AUTH},
  {"    --ca-native",
   "Load CA certs from the OS",
   CURLHELP_TLS},
  {"    --cacert <file>",
   "CA certificate to verify peer against",
   CURLHELP_TLS},
  {"    --capath <dir>",
   "CA directory to verify peer against",
   CURLHELP_TLS},
  {"-E, --cert <certificate[:password]>",
   "Client certificate file and password",
   CURLHELP_TLS},
  {"    --cert-status",
   "Verify server cert status OCSP-staple",
   CURLHELP_TLS},
  {"    --cert-type <type>",
   "Certificate type (DER/PEM/ENG/P12)",
   CURLHELP_TLS},
  {"    --ciphers <list of ciphers>",
   "SSL ciphers to use",
   CURLHELP_TLS},
  {"    --compressed",
   "Request compressed response",
   CURLHELP_HTTP},
  {"    --compressed-ssh",
   "Enable SSH compression",
   CURLHELP_SCP | CURLHELP_SSH},
  {"-K, --config <file>",
   "Read config from a file",
   CURLHELP_CURL},
  {"    --connect-timeout <seconds>",
   "Maximum time allowed to connect",
   CURLHELP_CONNECTION | CURLHELP_TIMEOUT},
  {"    --connect-to <HOST1:PORT1:HOST2:PORT2>",
   "Connect to host2 instead of host1",
   CURLHELP_CONNECTION | CURLHELP_DNS},
  {"-C, --continue-at <offset>",
   "Resumed transfer offset",
   CURLHELP_CONNECTION},
  {"-b, --cookie <data|filename>",
   "Send cookies from string/load from file",
   CURLHELP_HTTP},
  {"-c, --cookie-jar <filename>",
   "Save cookies to <filename> after operation",
   CURLHELP_HTTP},
  {"    --create-dirs",
   "Create necessary local directory hierarchy",
   CURLHELP_OUTPUT},
  {"    --create-file-mode <mode>",
   "File mode for created files",
   CURLHELP_SFTP | CURLHELP_SCP | CURLHELP_FILE | CURLHELP_UPLOAD},
  {"    --crlf",
   "Convert LF to CRLF in upload",
   CURLHELP_FTP | CURLHELP_SMTP},
  {"    --crlfile <file>",
   "Certificate Revocation list",
   CURLHELP_TLS},
  {"    --curves <list>",
   "(EC) TLS key exchange algorithms to request",
   CURLHELP_TLS},
  {"-d, --data <data>",
   "HTTP POST data",
   CURLHELP_IMPORTANT | CURLHELP_HTTP | CURLHELP_POST | CURLHELP_UPLOAD},
  {"    --data-ascii <data>",
   "HTTP POST ASCII data",
   CURLHELP_HTTP | CURLHELP_POST | CURLHELP_UPLOAD},
  {"    --data-binary <data>",
   "HTTP POST binary data",
   CURLHELP_HTTP | CURLHELP_POST | CURLHELP_UPLOAD},
  {"    --data-raw <data>",
   "HTTP POST data, '@' allowed",
   CURLHELP_HTTP | CURLHELP_POST | CURLHELP_UPLOAD},
  {"    --data-urlencode <data>",
   "HTTP POST data URL encoded",
   CURLHELP_HTTP | CURLHELP_POST | CURLHELP_UPLOAD},
  {"    --delegation <LEVEL>",
   "GSS-API delegation permission",
   CURLHELP_AUTH},
  {"    --digest",
   "HTTP Digest Authentication",
   CURLHELP_PROXY | CURLHELP_AUTH | CURLHELP_HTTP},
  {"-q, --disable",
   "Disable .curlrc",
   CURLHELP_CURL},
  {"    --disable-eprt",
   "Inhibit using EPRT or LPRT",
   CURLHELP_FTP},
  {"    --disable-epsv",
   "Inhibit using EPSV",
   CURLHELP_FTP},
  {"    --disallow-username-in-url",
   "Disallow username in URL",
   CURLHELP_CURL},
  {"    --dns-interface <interface>",
   "Interface to use for DNS requests",
   CURLHELP_DNS},
  {"    --dns-ipv4-addr <address>",
   "IPv4 address to use for DNS requests",
   CURLHELP_DNS},
  {"    --dns-ipv6-addr <address>",
   "IPv6 address to use for DNS requests",
   CURLHELP_DNS},
  {"    --dns-servers <addresses>",
   "DNS server addrs to use",
   CURLHELP_DNS},
  {"    --doh-cert-status",
   "Verify DoH server cert status OCSP-staple",
   CURLHELP_DNS | CURLHELP_TLS},
  {"    --doh-insecure",
   "Allow insecure DoH server connections",
   CURLHELP_DNS | CURLHELP_TLS},
  {"    --doh-url <URL>",
   "Resolve hostnames over DoH",
   CURLHELP_DNS},
  {"    --dump-ca-embed",
   "Write the embedded CA bundle to standard output",
   CURLHELP_HTTP | CURLHELP_PROXY | CURLHELP_TLS},
  {"-D, --dump-header <filename>",
   "Write the received headers to <filename>",
   CURLHELP_HTTP | CURLHELP_FTP},
  {"    --ech <config>",
   "Configure ECH",
   CURLHELP_TLS},
  {"    --egd-file <file>",
   "EGD socket path for random data",
   CURLHELP_DEPRECATED},
  {"    --engine <name>",
   "Crypto engine to use",
   CURLHELP_TLS},
  {"    --etag-compare <file>",
   "Load ETag from file",
   CURLHELP_HTTP},
  {"    --etag-save <file>",
   "Parse incoming ETag and save to a file",
   CURLHELP_HTTP},
  {"    --expect100-timeout <seconds>",
   "How long to wait for 100-continue",
   CURLHELP_HTTP | CURLHELP_TIMEOUT},
  {"-f, --fail",
   "Fail fast with no output on HTTP errors",
   CURLHELP_IMPORTANT | CURLHELP_HTTP},
  {"    --fail-early",
   "Fail on first transfer error",
   CURLHELP_CURL | CURLHELP_GLOBAL},
  {"    --fail-with-body",
   "Fail on HTTP errors but save the body",
   CURLHELP_HTTP | CURLHELP_OUTPUT},
  {"    --false-start",
   "Enable TLS False Start",
   CURLHELP_TLS},
  {"-F, --form <name=content>",
   "Specify multipart MIME data",
   CURLHELP_HTTP | CURLHELP_UPLOAD | CURLHELP_POST | CURLHELP_IMAP |
   CURLHELP_SMTP},
  {"    --form-escape",
   "Escape form fields using backslash",
   CURLHELP_HTTP | CURLHELP_UPLOAD | CURLHELP_POST},
  {"    --form-string <name=string>",
   "Specify multipart MIME data",
   CURLHELP_HTTP | CURLHELP_UPLOAD | CURLHELP_POST | CURLHELP_SMTP |
   CURLHELP_IMAP},
  {"    --ftp-account <data>",
   "Account data string",
   CURLHELP_FTP | CURLHELP_AUTH},
  {"    --ftp-alternative-to-user <command>",
   "String to replace USER [name]",
   CURLHELP_FTP},
  {"    --ftp-create-dirs",
   "Create the remote dirs if not present",
   CURLHELP_FTP | CURLHELP_SFTP},
  {"    --ftp-method <method>",
   "Control CWD usage",
   CURLHELP_FTP},
  {"    --ftp-pasv",
   "Send PASV/EPSV instead of PORT",
   CURLHELP_FTP},
  {"-P, --ftp-port <address>",
   "Send PORT instead of PASV",
   CURLHELP_FTP},
  {"    --ftp-pret",
   "Send PRET before PASV",
   CURLHELP_FTP},
  {"    --ftp-skip-pasv-ip",
   "Skip the IP address for PASV",
   CURLHELP_FTP},
  {"    --ftp-ssl-ccc",
   "Send CCC after authenticating",
   CURLHELP_FTP | CURLHELP_TLS},
  {"    --ftp-ssl-ccc-mode <active/passive>",
   "Set CCC mode",
   CURLHELP_FTP | CURLHELP_TLS},
  {"    --ftp-ssl-control",
   "Require TLS for login, clear for transfer",
   CURLHELP_FTP | CURLHELP_TLS},
  {"-G, --get",
   "Put the post data in the URL and use GET",
   CURLHELP_HTTP},
  {"-g, --globoff",
   "Disable URL globbing with {} and []",
   CURLHELP_CURL},
  {"    --happy-eyeballs-timeout-ms <ms>",
   "Time for IPv6 before IPv4",
   CURLHELP_CONNECTION | CURLHELP_TIMEOUT},
  {"    --haproxy-clientip <ip>",
   "Set address in HAProxy PROXY",
   CURLHELP_HTTP | CURLHELP_PROXY},
  {"    --haproxy-protocol",
   "Send HAProxy PROXY protocol v1 header",
   CURLHELP_HTTP | CURLHELP_PROXY},
  {"-I, --head",
   "Show document info only",
   CURLHELP_HTTP | CURLHELP_FTP | CURLHELP_FILE},
  {"-H, --header <header/@file>",
   "Pass custom header(s) to server",
   CURLHELP_HTTP | CURLHELP_IMAP | CURLHELP_SMTP},
  {"-h, --help <subject>",
   "Get help for commands",
   CURLHELP_IMPORTANT | CURLHELP_CURL},
  {"    --hostpubmd5 <md5>",
   "Acceptable MD5 hash of host public key",
   CURLHELP_SFTP | CURLHELP_SCP | CURLHELP_SSH},
  {"    --hostpubsha256 <sha256>",
   "Acceptable SHA256 hash of host public key",
   CURLHELP_SFTP | CURLHELP_SCP | CURLHELP_SSH},
  {"    --hsts <filename>",
   "Enable HSTS with this cache file",
   CURLHELP_HTTP},
  {"    --http0.9",
   "Allow HTTP 0.9 responses",
   CURLHELP_HTTP},
  {"-0, --http1.0",
   "Use HTTP 1.0",
   CURLHELP_HTTP},
  {"    --http1.1",
   "Use HTTP 1.1",
   CURLHELP_HTTP},
  {"    --http2",
   "Use HTTP/2",
   CURLHELP_HTTP},
  {"    --http2-prior-knowledge",
   "Use HTTP 2 without HTTP/1.1 Upgrade",
   CURLHELP_HTTP},
  {"    --http3",
   "Use HTTP v3",
   CURLHELP_HTTP},
  {"    --http3-only",
   "Use HTTP v3 only",
   CURLHELP_HTTP},
  {"    --ignore-content-length",
   "Ignore the size of the remote resource",
   CURLHELP_HTTP | CURLHELP_FTP},
  {"-k, --insecure",
   "Allow insecure server connections",
   CURLHELP_TLS | CURLHELP_SFTP | CURLHELP_SCP | CURLHELP_SSH},
  {"    --interface <name>",
   "Use network interface",
   CURLHELP_CONNECTION},
  {"    --ip-tos <string>",
   "Set IP Type of Service or Traffic Class",
   CURLHELP_CONNECTION},
  {"    --ipfs-gateway <URL>",
   "Gateway for IPFS",
   CURLHELP_CURL},
  {"-4, --ipv4",
   "Resolve names to IPv4 addresses",
   CURLHELP_CONNECTION | CURLHELP_DNS},
  {"-6, --ipv6",
   "Resolve names to IPv6 addresses",
   CURLHELP_CONNECTION | CURLHELP_DNS},
  {"    --json <data>",
   "HTTP POST JSON",
   CURLHELP_HTTP | CURLHELP_POST | CURLHELP_UPLOAD},
  {"-j, --junk-session-cookies",
   "Ignore session cookies read from file",
   CURLHELP_HTTP},
  {"    --keepalive-cnt <integer>",
   "Maximum number of keepalive probes",
   CURLHELP_CONNECTION},
  {"    --keepalive-time <seconds>",
   "Interval time for keepalive probes",
   CURLHELP_CONNECTION | CURLHELP_TIMEOUT},
  {"    --key <key>",
   "Private key filename",
   CURLHELP_TLS | CURLHELP_SSH},
  {"    --key-type <type>",
   "Private key file type (DER/PEM/ENG)",
   CURLHELP_TLS},
  {"    --krb <level>",
   "Enable Kerberos with security <level>",
   CURLHELP_FTP},
  {"    --libcurl <file>",
   "Generate libcurl code for this command line",
   CURLHELP_CURL | CURLHELP_GLOBAL},
  {"    --limit-rate <speed>",
   "Limit transfer speed to RATE",
   CURLHELP_CONNECTION},
  {"-l, --list-only",
   "List only mode",
   CURLHELP_FTP | CURLHELP_POP3 | CURLHELP_SFTP | CURLHELP_FILE},
  {"    --local-port <range>",
   "Use a local port number within RANGE",
   CURLHELP_CONNECTION},
  {"-L, --location",
   "Follow redirects",
   CURLHELP_HTTP},
  {"    --location-trusted",
   "As --location, but send auth to other hosts",
   CURLHELP_HTTP | CURLHELP_AUTH},
  {"    --login-options <options>",
   "Server login options",
   CURLHELP_IMAP | CURLHELP_POP3 | CURLHELP_SMTP | CURLHELP_AUTH |
   CURLHELP_LDAP},
  {"    --mail-auth <address>",
   "Originator address of the original email",
   CURLHELP_SMTP},
  {"    --mail-from <address>",
   "Mail from this address",
   CURLHELP_SMTP},
  {"    --mail-rcpt <address>",
   "Mail to this address",
   CURLHELP_SMTP},
  {"    --mail-rcpt-allowfails",
   "Allow RCPT TO command to fail",
   CURLHELP_SMTP},
  {"-M, --manual",
   "Display the full manual",
   CURLHELP_CURL},
  {"    --max-filesize <bytes>",
   "Maximum file size to download",
   CURLHELP_CONNECTION},
  {"    --max-redirs <num>",
   "Maximum number of redirects allowed",
   CURLHELP_HTTP},
  {"-m, --max-time <seconds>",
   "Maximum time allowed for transfer",
   CURLHELP_CONNECTION | CURLHELP_TIMEOUT},
  {"    --metalink",
   "Process given URLs as metalink XML file",
   CURLHELP_DEPRECATED},
  {"    --mptcp",
   "Enable Multipath TCP",
   CURLHELP_CONNECTION},
  {"    --negotiate",
   "Use HTTP Negotiate (SPNEGO) authentication",
   CURLHELP_AUTH | CURLHELP_HTTP},
  {"-n, --netrc",
   "Must read .netrc for username and password",
   CURLHELP_AUTH},
  {"    --netrc-file <filename>",
   "Specify FILE for netrc",
   CURLHELP_AUTH},
  {"    --netrc-optional",
   "Use either .netrc or URL",
   CURLHELP_AUTH},
  {"-:, --next",
   "Make next URL use separate options",
   CURLHELP_CURL},
  {"    --no-alpn",
   "Disable the ALPN TLS extension",
   CURLHELP_TLS | CURLHELP_HTTP},
  {"-N, --no-buffer",
   "Disable buffering of the output stream",
   CURLHELP_OUTPUT},
  {"    --no-clobber",
   "Do not overwrite files that already exist",
   CURLHELP_OUTPUT},
  {"    --no-keepalive",
   "Disable TCP keepalive on the connection",
   CURLHELP_CONNECTION},
  {"    --no-npn",
   "Disable the NPN TLS extension",
   CURLHELP_DEPRECATED},
  {"    --no-progress-meter",
   "Do not show the progress meter",
   CURLHELP_VERBOSE},
  {"    --no-sessionid",
   "Disable SSL session-ID reusing",
   CURLHELP_TLS},
  {"    --noproxy <no-proxy-list>",
   "List of hosts which do not use proxy",
   CURLHELP_PROXY},
  {"    --ntlm",
   "HTTP NTLM authentication",
   CURLHELP_AUTH | CURLHELP_HTTP},
  {"    --ntlm-wb",
   "HTTP NTLM authentication with winbind",
   CURLHELP_DEPRECATED},
  {"    --oauth2-bearer <token>",
   "OAuth 2 Bearer Token",
   CURLHELP_AUTH | CURLHELP_IMAP | CURLHELP_POP3 | CURLHELP_SMTP |
   CURLHELP_LDAP},
  {"-o, --output <file>",
   "Write to file instead of stdout",
   CURLHELP_IMPORTANT | CURLHELP_OUTPUT},
  {"    --output-dir <dir>",
   "Directory to save files in",
   CURLHELP_OUTPUT},
  {"-Z, --parallel",
   "Perform transfers in parallel",
   CURLHELP_CONNECTION | CURLHELP_CURL | CURLHELP_GLOBAL},
  {"    --parallel-immediate",
   "Do not wait for multiplexing",
   CURLHELP_CONNECTION | CURLHELP_CURL | CURLHELP_GLOBAL},
  {"    --parallel-max <num>",
   "Maximum concurrency for parallel transfers",
   CURLHELP_CONNECTION | CURLHELP_CURL | CURLHELP_GLOBAL},
  {"    --pass <phrase>",
   "Passphrase for the private key",
   CURLHELP_SSH | CURLHELP_TLS | CURLHELP_AUTH},
  {"    --path-as-is",
   "Do not squash .. sequences in URL path",
   CURLHELP_CURL},
  {"    --pinnedpubkey <hashes>",
   "Public key to verify peer against",
   CURLHELP_TLS},
  {"    --post301",
   "Do not switch to GET after a 301 redirect",
   CURLHELP_HTTP | CURLHELP_POST},
  {"    --post302",
   "Do not switch to GET after a 302 redirect",
   CURLHELP_HTTP | CURLHELP_POST},
  {"    --post303",
   "Do not switch to GET after a 303 redirect",
   CURLHELP_HTTP | CURLHELP_POST},
  {"    --preproxy [protocol://]host[:port]",
   "Use this proxy first",
   CURLHELP_PROXY},
  {"-#, --progress-bar",
   "Display transfer progress as a bar",
   CURLHELP_VERBOSE | CURLHELP_GLOBAL},
  {"    --proto <protocols>",
   "Enable/disable PROTOCOLS",
   CURLHELP_CONNECTION | CURLHELP_CURL},
  {"    --proto-default <protocol>",
   "Use PROTOCOL for any URL missing a scheme",
   CURLHELP_CONNECTION | CURLHELP_CURL},
  {"    --proto-redir <protocols>",
   "Enable/disable PROTOCOLS on redirect",
   CURLHELP_CONNECTION | CURLHELP_CURL},
  {"-x, --proxy [protocol://]host[:port]",
   "Use this proxy",
   CURLHELP_PROXY},
  {"    --proxy-anyauth",
   "Pick any proxy authentication method",
   CURLHELP_PROXY | CURLHELP_AUTH},
  {"    --proxy-basic",
   "Use Basic authentication on the proxy",
   CURLHELP_PROXY | CURLHELP_AUTH},
  {"    --proxy-ca-native",
   "Load CA certs from the OS to verify proxy",
   CURLHELP_TLS},
  {"    --proxy-cacert <file>",
   "CA certificates to verify proxy against",
   CURLHELP_PROXY | CURLHELP_TLS},
  {"    --proxy-capath <dir>",
   "CA directory to verify proxy against",
   CURLHELP_PROXY | CURLHELP_TLS},
  {"    --proxy-cert <cert[:passwd]>",
   "Set client certificate for proxy",
   CURLHELP_PROXY | CURLHELP_TLS},
  {"    --proxy-cert-type <type>",
   "Client certificate type for HTTPS proxy",
   CURLHELP_PROXY | CURLHELP_TLS},
  {"    --proxy-ciphers <list>",
   "SSL ciphers to use for proxy",
   CURLHELP_PROXY | CURLHELP_TLS},
  {"    --proxy-crlfile <file>",
   "Set a CRL list for proxy",
   CURLHELP_PROXY | CURLHELP_TLS},
  {"    --proxy-digest",
   "Digest auth with the proxy",
   CURLHELP_PROXY | CURLHELP_TLS},
  {"    --proxy-header <header/@file>",
   "Pass custom header(s) to proxy",
   CURLHELP_PROXY},
  {"    --proxy-http2",
   "Use HTTP/2 with HTTPS proxy",
   CURLHELP_HTTP | CURLHELP_PROXY},
  {"    --proxy-insecure",
   "Skip HTTPS proxy cert verification",
   CURLHELP_PROXY | CURLHELP_TLS},
  {"    --proxy-key <key>",
   "Private key for HTTPS proxy",
   CURLHELP_PROXY | CURLHELP_TLS},
  {"    --proxy-key-type <type>",
   "Private key file type for proxy",
   CURLHELP_PROXY | CURLHELP_TLS},
  {"    --proxy-negotiate",
   "HTTP Negotiate (SPNEGO) auth with the proxy",
   CURLHELP_PROXY | CURLHELP_AUTH},
  {"    --proxy-ntlm",
   "NTLM authentication with the proxy",
   CURLHELP_PROXY | CURLHELP_AUTH},
  {"    --proxy-pass <phrase>",
   "Passphrase for private key for HTTPS proxy",
   CURLHELP_PROXY | CURLHELP_TLS | CURLHELP_AUTH},
  {"    --proxy-pinnedpubkey <hashes>",
   "FILE/HASHES public key to verify proxy with",
   CURLHELP_PROXY | CURLHELP_TLS},
  {"    --proxy-service-name <name>",
   "SPNEGO proxy service name",
   CURLHELP_PROXY | CURLHELP_TLS},
  {"    --proxy-ssl-allow-beast",
   "Allow this security flaw for HTTPS proxy",
   CURLHELP_PROXY | CURLHELP_TLS},
  {"    --proxy-ssl-auto-client-cert",
   "Auto client certificate for proxy",
   CURLHELP_PROXY | CURLHELP_TLS},
  {"    --proxy-tls13-ciphers <ciphersuite list>",
   "TLS 1.3 proxy cipher suites",
   CURLHELP_PROXY | CURLHELP_TLS},
  {"    --proxy-tlsauthtype <type>",
   "TLS authentication type for HTTPS proxy",
   CURLHELP_PROXY | CURLHELP_TLS | CURLHELP_AUTH},
  {"    --proxy-tlspassword <string>",
   "TLS password for HTTPS proxy",
   CURLHELP_PROXY | CURLHELP_TLS | CURLHELP_AUTH},
  {"    --proxy-tlsuser <name>",
   "TLS username for HTTPS proxy",
   CURLHELP_PROXY | CURLHELP_TLS | CURLHELP_AUTH},
  {"    --proxy-tlsv1",
   "TLSv1 for HTTPS proxy",
   CURLHELP_PROXY | CURLHELP_TLS | CURLHELP_AUTH},
  {"-U, --proxy-user <user:password>",
   "Proxy user and password",
   CURLHELP_PROXY | CURLHELP_AUTH},
  {"    --proxy1.0 <host[:port]>",
   "Use HTTP/1.0 proxy on given port",
   CURLHELP_PROXY},
  {"-p, --proxytunnel",
   "HTTP proxy tunnel (using CONNECT)",
   CURLHELP_PROXY},
  {"    --pubkey <key>",
   "SSH Public key filename",
   CURLHELP_SFTP | CURLHELP_SCP | CURLHELP_SSH | CURLHELP_AUTH},
  {"-Q, --quote <command>",
   "Send command(s) to server before transfer",
   CURLHELP_FTP | CURLHELP_SFTP},
  {"    --random-file <file>",
   "File for reading random data from",
   CURLHELP_DEPRECATED},
  {"-r, --range <range>",
   "Retrieve only the bytes within RANGE",
   CURLHELP_HTTP | CURLHELP_FTP | CURLHELP_SFTP | CURLHELP_FILE},
  {"    --rate <max request rate>",
   "Request rate for serial transfers",
   CURLHELP_CONNECTION | CURLHELP_GLOBAL},
  {"    --raw",
   "Do HTTP raw; no transfer decoding",
   CURLHELP_HTTP},
  {"-e, --referer <URL>",
   "Referrer URL",
   CURLHELP_HTTP},
  {"-J, --remote-header-name",
   "Use the header-provided filename",
   CURLHELP_OUTPUT},
  {"-O, --remote-name",
   "Write output to file named as remote file",
   CURLHELP_IMPORTANT | CURLHELP_OUTPUT},
  {"    --remote-name-all",
   "Use the remote filename for all URLs",
   CURLHELP_OUTPUT},
  {"-R, --remote-time",
   "Set remote file's time on local output",
   CURLHELP_OUTPUT},
  {"    --remove-on-error",
   "Remove output file on errors",
   CURLHELP_OUTPUT},
  {"-X, --request <method>",
   "Specify request method to use",
   CURLHELP_CONNECTION | CURLHELP_POP3 | CURLHELP_FTP | CURLHELP_IMAP |
   CURLHELP_SMTP},
  {"    --request-target <path>",
   "Specify the target for this request",
   CURLHELP_HTTP},
  {"    --resolve <[+]host:port:addr[,addr]...>",
   "Resolve host+port to address",
   CURLHELP_CONNECTION | CURLHELP_DNS},
  {"    --retry <num>",
   "Retry request if transient problems occur",
   CURLHELP_CURL},
  {"    --retry-all-errors",
   "Retry all errors (with --retry)",
   CURLHELP_CURL},
  {"    --retry-connrefused",
   "Retry on connection refused (with --retry)",
   CURLHELP_CURL},
  {"    --retry-delay <seconds>",
   "Wait time between retries",
   CURLHELP_CURL | CURLHELP_TIMEOUT},
  {"    --retry-max-time <seconds>",
   "Retry only within this period",
   CURLHELP_CURL | CURLHELP_TIMEOUT},
  {"    --sasl-authzid <identity>",
   "Identity for SASL PLAIN authentication",
   CURLHELP_AUTH},
  {"    --sasl-ir",
   "Initial response in SASL authentication",
   CURLHELP_AUTH},
  {"    --service-name <name>",
   "SPNEGO service name",
   CURLHELP_AUTH},
  {"-S, --show-error",
   "Show error even when -s is used",
   CURLHELP_CURL | CURLHELP_GLOBAL},
  {"-i, --show-headers",
   "Show response headers in output",
   CURLHELP_IMPORTANT | CURLHELP_VERBOSE | CURLHELP_OUTPUT},
  {"-s, --silent",
   "Silent mode",
   CURLHELP_IMPORTANT | CURLHELP_VERBOSE},
  {"    --skip-existing",
   "Skip download if local file already exists",
   CURLHELP_CURL | CURLHELP_OUTPUT},
  {"    --socks4 <host[:port]>",
   "SOCKS4 proxy on given host + port",
   CURLHELP_PROXY},
  {"    --socks4a <host[:port]>",
   "SOCKS4a proxy on given host + port",
   CURLHELP_PROXY},
  {"    --socks5 <host[:port]>",
   "SOCKS5 proxy on given host + port",
   CURLHELP_PROXY},
  {"    --socks5-basic",
   "Username/password auth for SOCKS5 proxies",
   CURLHELP_PROXY | CURLHELP_AUTH},
  {"    --socks5-gssapi",
   "Enable GSS-API auth for SOCKS5 proxies",
   CURLHELP_PROXY | CURLHELP_AUTH},
  {"    --socks5-gssapi-nec",
   "Compatibility with NEC SOCKS5 server",
   CURLHELP_PROXY | CURLHELP_AUTH},
  {"    --socks5-gssapi-service <name>",
   "SOCKS5 proxy service name for GSS-API",
   CURLHELP_PROXY | CURLHELP_AUTH},
  {"    --socks5-hostname <host[:port]>",
   "SOCKS5 proxy, pass hostname to proxy",
   CURLHELP_PROXY},
  {"-Y, --speed-limit <speed>",
   "Stop transfers slower than this",
   CURLHELP_CONNECTION},
  {"-y, --speed-time <seconds>",
   "Trigger 'speed-limit' abort after this time",
   CURLHELP_CONNECTION | CURLHELP_TIMEOUT},
  {"    --ssl",
   "Try enabling TLS",
   CURLHELP_TLS | CURLHELP_IMAP | CURLHELP_POP3 | CURLHELP_SMTP |
   CURLHELP_LDAP},
  {"    --ssl-allow-beast",
   "Allow security flaw to improve interop",
   CURLHELP_TLS},
  {"    --ssl-auto-client-cert",
   "Use auto client certificate (Schannel)",
   CURLHELP_TLS},
  {"    --ssl-no-revoke",
   "Disable cert revocation checks (Schannel)",
   CURLHELP_TLS},
  {"    --ssl-reqd",
   "Require SSL/TLS",
   CURLHELP_TLS | CURLHELP_IMAP | CURLHELP_POP3 | CURLHELP_SMTP |
   CURLHELP_LDAP},
  {"    --ssl-revoke-best-effort",
   "Ignore missing cert CRL dist points",
   CURLHELP_TLS},
  {"-2, --sslv2",
   "SSLv2",
   CURLHELP_DEPRECATED},
  {"-3, --sslv3",
   "SSLv3",
   CURLHELP_DEPRECATED},
  {"    --stderr <file>",
   "Where to redirect stderr",
   CURLHELP_VERBOSE | CURLHELP_GLOBAL},
  {"    --styled-output",
   "Enable styled output for HTTP headers",
   CURLHELP_VERBOSE | CURLHELP_GLOBAL},
  {"    --suppress-connect-headers",
   "Suppress proxy CONNECT response headers",
   CURLHELP_PROXY},
  {"    --tcp-fastopen",
   "Use TCP Fast Open",
   CURLHELP_CONNECTION},
  {"    --tcp-nodelay",
   "Set TCP_NODELAY",
   CURLHELP_CONNECTION},
  {"-t, --telnet-option <opt=val>",
   "Set telnet option",
   CURLHELP_TELNET},
  {"    --tftp-blksize <value>",
   "Set TFTP BLKSIZE option",
   CURLHELP_TFTP},
  {"    --tftp-no-options",
   "Do not send any TFTP options",
   CURLHELP_TFTP},
  {"-z, --time-cond <time>",
   "Transfer based on a time condition",
   CURLHELP_HTTP | CURLHELP_FTP},
  {"    --tls-max <VERSION>",
   "Maximum allowed TLS version",
   CURLHELP_TLS},
  {"    --tls13-ciphers <list>",
   "TLS 1.3 cipher suites to use",
   CURLHELP_TLS},
  {"    --tlsauthtype <type>",
   "TLS authentication type",
   CURLHELP_TLS | CURLHELP_AUTH},
  {"    --tlspassword <string>",
   "TLS password",
   CURLHELP_TLS | CURLHELP_AUTH},
  {"    --tlsuser <name>",
   "TLS username",
   CURLHELP_TLS | CURLHELP_AUTH},
  {"-1, --tlsv1",
   "TLSv1.0 or greater",
   CURLHELP_TLS},
  {"    --tlsv1.0",
   "TLSv1.0 or greater",
   CURLHELP_TLS},
  {"    --tlsv1.1",
   "TLSv1.1 or greater",
   CURLHELP_TLS},
  {"    --tlsv1.2",
   "TLSv1.2 or greater",
   CURLHELP_TLS},
  {"    --tlsv1.3",
   "TLSv1.3 or greater",
   CURLHELP_TLS},
  {"    --tr-encoding",
   "Request compressed transfer encoding",
   CURLHELP_HTTP},
  {"    --trace <file>",
   "Write a debug trace to FILE",
   CURLHELP_VERBOSE | CURLHELP_GLOBAL},
  {"    --trace-ascii <file>",
   "Like --trace, but without hex output",
   CURLHELP_VERBOSE | CURLHELP_GLOBAL},
  {"    --trace-config <string>",
   "Details to log in trace/verbose output",
   CURLHELP_VERBOSE | CURLHELP_GLOBAL},
  {"    --trace-ids",
   "Transfer + connection ids in verbose output",
   CURLHELP_VERBOSE | CURLHELP_GLOBAL},
  {"    --trace-time",
   "Add time stamps to trace/verbose output",
   CURLHELP_VERBOSE | CURLHELP_GLOBAL},
  {"    --unix-socket <path>",
   "Connect through this Unix domain socket",
   CURLHELP_CONNECTION},
  {"-T, --upload-file <file>",
   "Transfer local FILE to destination",
   CURLHELP_IMPORTANT | CURLHELP_UPLOAD},
  {"    --url <url>",
   "URL to work with",
   CURLHELP_CURL},
  {"    --url-query <data>",
   "Add a URL query part",
   CURLHELP_HTTP | CURLHELP_POST | CURLHELP_UPLOAD},
  {"-B, --use-ascii",
   "Use ASCII/text transfer",
   CURLHELP_FTP | CURLHELP_OUTPUT | CURLHELP_LDAP},
  {"-u, --user <user:password>",
   "Server user and password",
   CURLHELP_IMPORTANT | CURLHELP_AUTH},
  {"-A, --user-agent <name>",
   "Send User-Agent <name> to server",
   CURLHELP_IMPORTANT | CURLHELP_HTTP},
  {"    --variable <[%]name=text/@file>",
   "Set variable",
   CURLHELP_CURL},
  {"-v, --verbose",
   "Make the operation more talkative",
   CURLHELP_IMPORTANT | CURLHELP_VERBOSE | CURLHELP_GLOBAL},
  {"-V, --version",
   "Show version number and quit",
   CURLHELP_IMPORTANT | CURLHELP_CURL},
  {"    --vlan-priority <priority>",
   "Set VLAN priority",
   CURLHELP_CONNECTION},
  {"-w, --write-out <format>",
   "Output FORMAT after completion",
   CURLHELP_VERBOSE},
  {"    --xattr",
   "Store metadata in extended file attributes",
   CURLHELP_OUTPUT},
  { NULL, NULL, 0 }
};
