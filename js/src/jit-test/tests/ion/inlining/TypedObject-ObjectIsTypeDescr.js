// |jit-test| skip-if: !this.TypedObject
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/* Used to verify that the JIT resolves the ObjectIsTypeDescr tests
 * internal to Type.equivalent().
 *
 * In this case the argument type is always a type descriptor object,
 * so ObjectIsTypeDescr resolves to true and there should be no
 * exceptions.
 *
 * Load this into the js shell with IONFLAGS=logs, then exit and run
 * iongraph.  You're looking for a smallish function within the
 * "self-hosted" domain.  Look for a call to ObjectIsTypeDescr far
 * down in the graph for pass00, with a call to DescrToSource in a
 * subsequent block (all of this is at the mercy of the way the code
 * is currently written).
 */

var T = TypedObject;
var ST = new T.StructType({x:T.int32});

function check(v) {
    return v.equivalent(T.int32);
}

function test() {
    for ( var i=0 ; i < 1000 ; i++ )
	check(ST);
    return check(ST);
}

print(test());


