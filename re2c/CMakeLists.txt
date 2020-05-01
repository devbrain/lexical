set (src
actions.cc        code.cc           dfa.cc            enc.cc
input_api.cc      main.cc           mbo_getopt.cc     parser.cc
print.cc          range.cc          range_suffix.cc   scanner.cc
substr.cc         translate.cc      utf16.cc          utf16_range.cc
utf16_regexp.cc   utf8.cc           utf8_range.cc     utf8_regexp.cc
)

onyx_exec (re2c src hdr)
