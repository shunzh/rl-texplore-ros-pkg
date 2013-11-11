; Auto-generated. Do not edit!


(cl:in-package rl_msgs-msg)


;//! \htmlinclude RLAction.msg.html

(cl:defclass <RLAction> (roslisp-msg-protocol:ros-message)
  ((action
    :reader action
    :initarg :action
    :type cl:integer
    :initform 0))
)

(cl:defclass RLAction (<RLAction>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RLAction>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RLAction)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rl_msgs-msg:<RLAction> is deprecated: use rl_msgs-msg:RLAction instead.")))

(cl:ensure-generic-function 'action-val :lambda-list '(m))
(cl:defmethod action-val ((m <RLAction>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rl_msgs-msg:action-val is deprecated.  Use rl_msgs-msg:action instead.")
  (action m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RLAction>) ostream)
  "Serializes a message object of type '<RLAction>"
  (cl:let* ((signed (cl:slot-value msg 'action)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RLAction>) istream)
  "Deserializes a message object of type '<RLAction>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'action) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RLAction>)))
  "Returns string type for a message object of type '<RLAction>"
  "rl_msgs/RLAction")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RLAction)))
  "Returns string type for a message object of type 'RLAction"
  "rl_msgs/RLAction")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RLAction>)))
  "Returns md5sum for a message object of type '<RLAction>"
  "b028501ac85c840a01d50342b4cc9b6e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RLAction)))
  "Returns md5sum for a message object of type 'RLAction"
  "b028501ac85c840a01d50342b4cc9b6e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RLAction>)))
  "Returns full string definition for message of type '<RLAction>"
  (cl:format cl:nil "# Message for describing an action in RL~%~%int32 action~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RLAction)))
  "Returns full string definition for message of type 'RLAction"
  (cl:format cl:nil "# Message for describing an action in RL~%~%int32 action~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RLAction>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RLAction>))
  "Converts a ROS message object to a list"
  (cl:list 'RLAction
    (cl:cons ':action (action msg))
))
