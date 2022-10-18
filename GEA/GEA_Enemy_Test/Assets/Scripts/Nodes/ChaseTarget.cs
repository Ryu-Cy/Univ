using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;
using MBT;

namespace MBT
{
    [AddComponentMenu("")]
    [MBTNode("Tasks/Chase Target")]
    public class ChaseTarget : Leaf
    {
        public GameObjectReference objRef = new GameObjectReference(VarRefMode.DisableConstant);
        public TransformReference destination;
        public NavMeshAgent agent;
        public float stopDistance = 2f;
        [Tooltip("How often target position should be updated")]
        public float updateInterval = 1f;
        private float time = 0;

        public override void OnEnter()
        {
            time = 0;
            agent.isStopped = false;
            agent.SetDestination(destination.Value.position);
        }
        
        public override NodeResult Execute()
        {
            GameObject obj = objRef.Value;

            time += Time.deltaTime;

            // Update destination every given interval
            if (time > updateInterval)
            {
                // Reset time and update destination
                time = 0;
                agent.SetDestination(destination.Value.position);
            }
            // Check if path is ready
            if (agent.pathPending)
            {
                return NodeResult.running;
            }
            // Check if agent is very close to destination
            if (agent.remainingDistance < stopDistance 
                || (int)obj.GetComponent<Enemy>().State != 2)
            {
                return NodeResult.success;
            }
            // Check if there is any path (if not pending, it should be set)
            if (agent.hasPath)
            {
                return NodeResult.running;
            }

            // By default return failure
            return NodeResult.failure;
        }

        public override void OnExit()
        {
            agent.isStopped = true;
            // agent.ResetPath();
        }

        public override bool IsValid()
        {
            return !(destination.isInvalid || agent == null);
        }
    }
}
