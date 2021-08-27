import os;
os.chdir('/opt/Signadyne/python'); #path library
import signadyne;

hvi = signadyne.SD_HVI();
hvi.open('S:/PublicTemp/Software/issues/test-H3354_constants.HVI');
hvi.start();
print(hvi.readDoubleConstantWithIndex(0, "VoltConstant"));
