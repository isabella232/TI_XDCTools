/*
 *  ======== Linux86.getISAChain ========
 *  Linux86 implementation for ITarget.getISAChain()
 */
function getISAChain (isa)
{
    var myChain = ["x86", this.isa];
    var isaIn = (isa == null ? this.isa : isa);

    for (var i = 0; i < myChain.length; i++) {
        if (myChain[i] == isaIn) {
            break;
        }
    }

    if (i == myChain.length) {
        return (null);
    }
    else {
        return (myChain.slice(0, i + 1));
    }
}
/*
 *  @(#) gnu.targets; 1, 0, 1,0; 2-9-2020 18:50:41; /db/ztree/library/trees/xdc/xdc-I08/src/targets/
 */

