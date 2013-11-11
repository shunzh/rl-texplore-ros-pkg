; Auto-generated. Do not edit!


(cl:in-package rl_msgs-msg)


;//! \htmlinclude RLExperimentInfo.msg.html

(cl:defclass <RLExperimentInfo> (roslisp-msg-protocol:ros-message)
  ((episode_number
    :reader episode_number
    :initarg :episode_number
    :type cl:integer
    :initform 0)
   (episode_reward
    :reader episode_reward
    :initarg :episode_reward
    :type cl:float
    :initform 0.0)
   (number_actions
    :reader number_actions
    :initarg :number_actions
    :type cl:integer
    :initform 0))
)

(cl:defclass RLExperimentInfo (<RLExperimentInfo>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RLExperimentInfo>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RLExperimentInfo)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rl_msgs-msg:<RLExperimentInfo> is deprecated: use rl_msgs-msg:RLExperimentInfo instead.")))

(cl:ensure-generic-function 'episode_number-val :lambda-list '(m))
(cl:defmethod episode_number-val ((m <RLExperimentInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rl_msgs-msg:episode_number-val is deprecated.  Use rl_msgs-msg:episode_number instead.")
  (episode_number m))

(cl:ensure-generic-function 'episode_reward-val :lambda-list '(m))
(cl:defmethod episode_reward-val ((m <RLExperimentInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rl_msgs-msg:episode_reward-val is deprecated.  Use rl_msgs-msg:episode_reward instead.")
  (episode_reward m))

(cl:ensure-generic-function 'number_actions-val :lambda-list '(m))
(cl:defmethod number_actions-val ((m <RLExperimentInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rl_msgs-msg:number_actions-val is deprecated.  Use rl_msgs-msg:number_actions instead.")
  (number_actions m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RLExperimentInfo>) ostream)
  "Serializes a message object of type '<RLExperimentInfo>"
  (cl:let* ((signed (cl:slot-value msg 'episode_number)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'episode_reward))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'number_actions)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RLExperimentInfo>) istream)
  "Deserializes a message object of type '<RLExperimentInfo>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'episode_number) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'episode_reward) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'number_actions) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RLExperimentInfo>)))
  "Returns string type for a message object of type '<RLExperimentInfo>"
  "rl_msgs/RLExperimentInfo")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RLExperimentInfo)))
  "Returns string type for a message object of type 'RLExperimentInfo"
  "rl_msgs/RLExperimentInfo")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RLExperimentInfo>)))
  "Returns md5sum for a message object of type '<RLExperimentInfo>"
  "df389dab0f017dc2a66e6cedd44b7a1e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RLExperimentInfo)))
  "Returns md5sum for a message object of type 'RLExperimentInfo"
  "df389dab0f017dc2a66e6cedd44b7a1e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RLExperimentInfo>)))
  "Returns full string definition for message of type '<RLExperimentInfo>"
  (cl:format cl:nil "# Message displaying / plotting / printing info about experiments~%~%int32 episode_number~%float32 episode_reward~%~%int32 number_actions~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RLExperimentInfo)))
  "Returns full string definition for message of type 'RLExperimentInfo"
  (cl:format cl:nil "# Message displaying / plotting / printing info about experiments~%~%int32 episode_number~%float32 episode_reward~%~%int32 number_actions~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RLExperimentInfo>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RLExperimentInfo>))
  "Converts a ROS message object to a list"
  (cl:list 'RLExperimentInfo
    (cl:cons ':episode_number (episode_number msg))
    (cl:cons ':episode_reward (episode_reward msg))
    (cl:cons ':number_actions (number_actions msg))
))
