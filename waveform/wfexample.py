import sys
sys.path.insert(0,r'C:\Users\xjian\Google 云端硬盘\AWGpy\waveform')
import waveform

x=r'C:\Users\xjian\Google 云端硬盘\AWGpy\test1.csv'
w1=waveform.wfgen(x)
w1.wf_gaussian(10000000)
