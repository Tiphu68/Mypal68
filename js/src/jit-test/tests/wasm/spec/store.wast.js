
// store.wast:3
let $1 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x84\x80\x80\x80\x00\x01\x60\x00\x00\x03\x8a\x80\x80\x80\x00\x09\x00\x00\x00\x00\x00\x00\x00\x00\x00\x05\x83\x80\x80\x80\x00\x01\x00\x01\x07\x97\x81\x80\x80\x00\x09\x0e\x61\x73\x2d\x62\x6c\x6f\x63\x6b\x2d\x76\x61\x6c\x75\x65\x00\x00\x0d\x61\x73\x2d\x6c\x6f\x6f\x70\x2d\x76\x61\x6c\x75\x65\x00\x01\x0b\x61\x73\x2d\x62\x72\x2d\x76\x61\x6c\x75\x65\x00\x02\x0e\x61\x73\x2d\x62\x72\x5f\x69\x66\x2d\x76\x61\x6c\x75\x65\x00\x03\x13\x61\x73\x2d\x62\x72\x5f\x69\x66\x2d\x76\x61\x6c\x75\x65\x2d\x63\x6f\x6e\x64\x00\x04\x11\x61\x73\x2d\x62\x72\x5f\x74\x61\x62\x6c\x65\x2d\x76\x61\x6c\x75\x65\x00\x05\x0f\x61\x73\x2d\x72\x65\x74\x75\x72\x6e\x2d\x76\x61\x6c\x75\x65\x00\x06\x0a\x61\x73\x2d\x69\x66\x2d\x74\x68\x65\x6e\x00\x07\x0a\x61\x73\x2d\x69\x66\x2d\x65\x6c\x73\x65\x00\x08\x0a\xac\x81\x80\x80\x00\x09\x8c\x80\x80\x80\x00\x00\x02\x40\x41\x00\x41\x01\x36\x02\x00\x0b\x0b\x8c\x80\x80\x80\x00\x00\x03\x40\x41\x00\x41\x01\x36\x02\x00\x0b\x0b\x8e\x80\x80\x80\x00\x00\x02\x40\x41\x00\x41\x01\x36\x02\x00\x0c\x00\x0b\x0b\x90\x80\x80\x80\x00\x00\x02\x40\x41\x00\x41\x01\x36\x02\x00\x41\x01\x0d\x00\x0b\x0b\x90\x80\x80\x80\x00\x00\x02\x40\x41\x06\x41\x00\x41\x01\x36\x02\x00\x0d\x00\x0b\x0b\x91\x80\x80\x80\x00\x00\x02\x40\x41\x00\x41\x01\x36\x02\x00\x41\x01\x0e\x00\x00\x0b\x0b\x8a\x80\x80\x80\x00\x00\x41\x00\x41\x01\x36\x02\x00\x0f\x0b\x8e\x80\x80\x80\x00\x00\x41\x01\x04\x40\x41\x00\x41\x01\x36\x02\x00\x0b\x0b\x8f\x80\x80\x80\x00\x00\x41\x00\x04\x40\x05\x41\x00\x41\x01\x36\x02\x00\x0b\x0b");

// store.wast:44
assert_return(() => call($1, "as-block-value", []));

// store.wast:45
assert_return(() => call($1, "as-loop-value", []));

// store.wast:47
assert_return(() => call($1, "as-br-value", []));

// store.wast:48
assert_return(() => call($1, "as-br_if-value", []));

// store.wast:49
assert_return(() => call($1, "as-br_if-value-cond", []));

// store.wast:50
assert_return(() => call($1, "as-br_table-value", []));

// store.wast:52
assert_return(() => call($1, "as-return-value", []));

// store.wast:54
assert_return(() => call($1, "as-if-then", []));

// store.wast:55
assert_return(() => call($1, "as-if-else", []));

// store.wast:57
assert_malformed("\x3c\x6d\x61\x6c\x66\x6f\x72\x6d\x65\x64\x20\x71\x75\x6f\x74\x65\x3e");

// store.wast:64
assert_malformed("\x3c\x6d\x61\x6c\x66\x6f\x72\x6d\x65\x64\x20\x71\x75\x6f\x74\x65\x3e");

// store.wast:72
assert_malformed("\x3c\x6d\x61\x6c\x66\x6f\x72\x6d\x65\x64\x20\x71\x75\x6f\x74\x65\x3e");

// store.wast:80
assert_malformed("\x3c\x6d\x61\x6c\x66\x6f\x72\x6d\x65\x64\x20\x71\x75\x6f\x74\x65\x3e");

// store.wast:87
assert_malformed("\x3c\x6d\x61\x6c\x66\x6f\x72\x6d\x65\x64\x20\x71\x75\x6f\x74\x65\x3e");

// store.wast:95
assert_malformed("\x3c\x6d\x61\x6c\x66\x6f\x72\x6d\x65\x64\x20\x71\x75\x6f\x74\x65\x3e");

// store.wast:102
assert_malformed("\x3c\x6d\x61\x6c\x66\x6f\x72\x6d\x65\x64\x20\x71\x75\x6f\x74\x65\x3e");

// store.wast:111
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x86\x80\x80\x80\x00\x01\x60\x01\x7f\x01\x7f\x03\x82\x80\x80\x80\x00\x01\x00\x05\x83\x80\x80\x80\x00\x01\x00\x01\x0a\x8f\x80\x80\x80\x00\x01\x89\x80\x80\x80\x00\x00\x41\x00\x41\x01\x36\x02\x00\x0b");

// store.wast:115
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x86\x80\x80\x80\x00\x01\x60\x01\x7e\x01\x7e\x03\x82\x80\x80\x80\x00\x01\x00\x05\x83\x80\x80\x80\x00\x01\x00\x01\x0a\x8f\x80\x80\x80\x00\x01\x89\x80\x80\x80\x00\x00\x41\x00\x42\x01\x37\x03\x00\x0b");

// store.wast:119
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x86\x80\x80\x80\x00\x01\x60\x01\x7d\x01\x7d\x03\x82\x80\x80\x80\x00\x01\x00\x05\x83\x80\x80\x80\x00\x01\x00\x01\x0a\x92\x80\x80\x80\x00\x01\x8c\x80\x80\x80\x00\x00\x41\x00\x43\x00\x00\x80\x3f\x38\x02\x00\x0b");

// store.wast:123
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x86\x80\x80\x80\x00\x01\x60\x01\x7c\x01\x7c\x03\x82\x80\x80\x80\x00\x01\x00\x05\x83\x80\x80\x80\x00\x01\x00\x01\x0a\x96\x80\x80\x80\x00\x01\x90\x80\x80\x80\x00\x00\x41\x00\x44\x00\x00\x00\x00\x00\x00\xf0\x3f\x39\x03\x00\x0b");

// store.wast:127
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x86\x80\x80\x80\x00\x01\x60\x01\x7f\x01\x7f\x03\x82\x80\x80\x80\x00\x01\x00\x05\x83\x80\x80\x80\x00\x01\x00\x01\x0a\x8f\x80\x80\x80\x00\x01\x89\x80\x80\x80\x00\x00\x41\x00\x41\x01\x3a\x00\x00\x0b");

// store.wast:131
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x86\x80\x80\x80\x00\x01\x60\x01\x7f\x01\x7f\x03\x82\x80\x80\x80\x00\x01\x00\x05\x83\x80\x80\x80\x00\x01\x00\x01\x0a\x8f\x80\x80\x80\x00\x01\x89\x80\x80\x80\x00\x00\x41\x00\x41\x01\x3b\x01\x00\x0b");

// store.wast:135
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x86\x80\x80\x80\x00\x01\x60\x01\x7e\x01\x7e\x03\x82\x80\x80\x80\x00\x01\x00\x05\x83\x80\x80\x80\x00\x01\x00\x01\x0a\x8f\x80\x80\x80\x00\x01\x89\x80\x80\x80\x00\x00\x41\x00\x42\x01\x3c\x00\x00\x0b");

// store.wast:139
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x86\x80\x80\x80\x00\x01\x60\x01\x7e\x01\x7e\x03\x82\x80\x80\x80\x00\x01\x00\x05\x83\x80\x80\x80\x00\x01\x00\x01\x0a\x8f\x80\x80\x80\x00\x01\x89\x80\x80\x80\x00\x00\x41\x00\x42\x01\x3d\x01\x00\x0b");

// store.wast:143
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x86\x80\x80\x80\x00\x01\x60\x01\x7e\x01\x7e\x03\x82\x80\x80\x80\x00\x01\x00\x05\x83\x80\x80\x80\x00\x01\x00\x01\x0a\x8f\x80\x80\x80\x00\x01\x89\x80\x80\x80\x00\x00\x41\x00\x42\x01\x3e\x02\x00\x0b");