Intuitively, it makes more sense that the ACK be the last byte received. Essentially, the receiving end says.

> I have received up to N bytes

Then, the sender will receive that ACK that says N and know to send byte N + 1

Instead, the ACK is the last byte received + 1. I don't know the justification for this

Whether the receiver acknowledges the last received byte (*I have received up to* x) or the next expected byte (*I have received everything before* x) provides the exact same information. It's just a matter of convention or definition.

You can actually interpret the sequence number either way, without a difference. However, the synchronization handshake might make more sense intuitively if you interpret it the *next expected* way. https://networkengineering.stackexchange.com/questions/79093/for-tcp-what-is-the-justification-that-acks-are-last-byte-received-1-and-not

http://gaia.cs.umass.edu/kurose_ross/knowledgechecks/problem.php?c=3&s=5

![image-20221213004303899](C:\Users\zzhez\AppData\Roaming\Typora\typora-user-images\image-20221213004303899.png)

The packet starts with 0. Lost 什么packet 就发送ACK + Packet No.# (注意是从0开始！一般是lost第五个包裹 发送ACK104 因为从0开始！！)

Fast Retransmit is a modification to the congestion avoidance algorithm. As in the fast retransmit algorithm, when the sender receives 3rd duplicated ACK, it assumes that the packet is lost and retransmit the packet without waiting for a retransmission timer to expire. After retransmission, the sender continues normal data transmission. That means TCP does not wait for the other end to acknowledge the retransmission.

